#include "../Inc/MySort.h"

void sort(Tape &input, Tape &output, const int &RAM) {

    std::vector<int> current;
    std::vector<Tape> tapes;

    while (!input.eot()) {

        for (int i = 0; i < RAM && !input.eot(); ++i) {
            int x = input.read();
            current.push_back(x);
            input.moveRight();
        }

        std::sort(current.rbegin(), current.rend());
        tapes.emplace_back("tmp\\" + std::to_string(tapes.size() + 1) + ".txt");
        for (const auto &elem : elements) {
            tapes.back().write(x);
            tapes.back().moveRight();
        }
        tapes.back().moveLeft();
        current.resize(0);
    }

    int tmp, min;
    while (true) {
        min = INT_MAX;
        auto cur_min = tapes.begin();
        bool flag = true;
        for (auto cur = tapes.begin(); cur != tapes.end(); ++it) {
            if (!cur->eot()) {
                tmp = cur->read();
                if (tmp <= min) {
                    min = tmp;
                    cur_min = cur;
                }
                flag = false;
            }
        }
        if (flag) {
            break;
        } else {
            cur_min->moveLeft();
            output.write(min);
            output.moveRight();
        }
    }
}
