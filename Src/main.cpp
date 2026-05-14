#include "../Inc/main.h"

int main() {
    try {
        std::string input, output;
        std::cout << "Specify the path to the input file:";
        std::cin >> input;
        std::cout << "Specify the path to the output file:";
        std::cin >> output;

        Data cur;
        cur.dread = D_READ;
        cur.dwrite = D_WRITE;
        cur.dmove = D_MOVE;

        Tape Tape_in(input, cur), Tape_out(output, cur);
        sort(Tape_in, Tape_out, RAM);
    } 
    catch (std::exception &e) {
        std::cerr << e.what();
    }

    return 0;
}
