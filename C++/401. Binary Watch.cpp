//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"

class Solution {
private:
    vector<string> res;
    vector<int> label;

    void search(int idx, int num) {
        if (idx >= 10) {
            return;
        }
        if (0 == num) {
            // record.
            string tmp;
            int hour =
                    8 * this->label[0] +
                    4 * this->label[1] +
                    2 * this->label[2] +
                    1 * this->label[3];
            int minutes = 32 * this->label[4] + 16 * this->label[5]
                          + 8 * this->label[6] + 4 * this->label[7]
                          + 2 * this->label[8] + 1 * this->label[9];
            if (hour > 11 || minutes > 59) {
                return;
            }
            if (0 == hour) {
                tmp += "0";
            } else {
                tmp += to_string(hour);
            }
            tmp += ":";
            if (minutes < 10) {
                if (0 == minutes) {
                    tmp += "00";
                } else {
                    tmp += "0";
                    tmp += to_string(minutes);
                }
            } else {
                tmp += to_string(minutes);
            }
            this->res.push_back(tmp);
            return;
        }

        // 该位使用。
        this->label[idx] = 1;
        this->search(idx + 1, num - 1);

        // 不使用。
        this->label[idx] = 0;
        this->search(idx + 1, num);
    }

public:
    vector<string> readBinaryWatch(int num) {
        this->label.clear();
        this->res.clear();
        for (int i = 0; i < 10; ++i) {
            this->label.push_back(0);
        }
        this->search(0, num);
        return this->res;
    }
};

int main() {
    return 0;
}