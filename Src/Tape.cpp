#include "Tape.h"

Tape::Tape(const std::string &path) : path(path) {
    if (std::filesystem::exists(path)) {
        file.open(path, std::fstream::in | std::fstream::out);
    } else {
        file.open(path, std::fstream::in | std::fstream::out | std::fstream::trunc);
    }

    if (file.is_open()) {
        readFromFile();
    } else {
        std::cerr << "The file with this path does not open." << std::endl;
    }

    file.exceptions(std::fstream::badbit | std::fstream::failbit);
}

Tape::Tape(const std::string &path, const Data &delays) : Tape(path) {
    this->delays = delays; 
}

Tape::~Tape() {
    if (file.is_open()) {
        file.close();
        file.open(path, std::fstream::out | std::fstream::trunc);
        file.clear();
        writeToFile();
        file.close();
    }
}

void Tape::readFromFile() {
    if (file.peek() == std::fstream::traits_type::eof()) {
        file.clear();
        return;
    }

    file.seekg(std::ios::beg);
    int x;
    while (!file.eof()) {
        file >> x;
        tape.push_back(x);
    }
    file.clear();
}

void Tape::writeToFile() {
    for (size_t i = 0; i < tape.size() - 1; ++i) {
        file << tape[i] << "\n";
    }
    file << tape.back();
}

int &Tape::read() {
    std::this_thread::sleep_for(std::chrono::milliseconds(delays.readDelay));
    return tape[pos];
}

void Tape::write(const int &x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delays.writeDelay));
    if (pos >= tape.size()) {
        tape.push_back(x);
    } else {
        tape[pos] = x;
    }
}

bool Tape::eot() const {
    return pos >= tape.size() || pos < 0;
}

void Tape::moveRight() {
    std::this_thread::sleep_for(std::chrono::milliseconds(delays.moveDelay));
    ++pos;
}

void Tape::moveLeft() {
    std::this_thread::sleep_for(std::chrono::milliseconds(delays.moveDelay));
    --pos;
}
