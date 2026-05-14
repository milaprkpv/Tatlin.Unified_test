#include <fstream>
#include <thread>
#include <chrono>
#include <vector>
#include <iostream>
#include <filesystem>

struct Data {
    int readDelay = 0;
    int writeDelay = 0;
    int moveDelay = 0;
};

class Tape {
public:
    explicit Tape(const std::string &path);
    Tape(const std::string &path, const Config &delays);
    ~Tape();

    Tape(Tape &&other) = default;
    Tape& operator=(Tape &&other) = default;

    Tape(const Tape&) = delete;
    Tape& operator=(const Tape&) = delete;

    int& read();
    void write(const int &elem);
    bool eot() const;
    void moveRight();
    void moveLeft();

private:
    void readFromFile();
    void writeToFile();

private:
    std::string path;
    std::fstream file;
    int pos = 0;
    Data delays;
    std::vector<int> tape;
};
