//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
private:
    vector<string> res;
    vector<char> path;

    void fun(int idx, string &digits) {
        int n = int(digits.length());
        if (idx >= n) {
            // record.
//            std::cout << idx << std::endl;
            string tmp;
            for (auto x:path) {
                tmp += x;
//                std::cout << x << std::endl;
            }
            this->res.push_back(tmp);

            return;
        }

        if ('2' == digits[idx]) {
            this->path[idx] = 'a';
            this->fun(idx + 1, digits);
            this->path[idx] = 'b';
            this->fun(idx + 1, digits);
            this->path[idx] = 'c';
            this->fun(idx + 1, digits);
        } else if ('3' == digits[idx]) {
            this->path[idx] = 'd';
            this->fun(idx + 1, digits);
            this->path[idx] = 'e';
            this->fun(idx + 1, digits);
            this->path[idx] = 'f';
            this->fun(idx + 1, digits);
        } else if ('4' == digits[idx]) {
            this->path[idx] = 'g';
            this->fun(idx + 1, digits);
            this->path[idx] = 'h';
            this->fun(idx + 1, digits);
            this->path[idx] = 'i';
            this->fun(idx + 1, digits);
        } else if ('5' == digits[idx]) {
            this->path[idx] = 'j';
            this->fun(idx + 1, digits);
            this->path[idx] = 'k';
            this->fun(idx + 1, digits);
            this->path[idx] = 'l';
            this->fun(idx + 1, digits);
        } else if ('6' == digits[idx]) {
            this->path[idx] = 'm';
            this->fun(idx + 1, digits);
            this->path[idx] = 'n';
            this->fun(idx + 1, digits);
            this->path[idx] = 'o';
            this->fun(idx + 1, digits);
        } else if ('7' == digits[idx]) {
            this->path[idx] = 'p';
            this->fun(idx + 1, digits);
            this->path[idx] = 'q';
            this->fun(idx + 1, digits);
            this->path[idx] = 'r';
            this->fun(idx + 1, digits);
            this->path[idx] = 's';
            this->fun(idx + 1, digits);
        } else if ('8' == digits[idx]) {
            this->path[idx] = 't';
            this->fun(idx + 1, digits);
            this->path[idx] = 'u';
            this->fun(idx + 1, digits);
            this->path[idx] = 'v';
            this->fun(idx + 1, digits);
        } else if ('9' == digits[idx]) {
            this->path[idx] = 'w';
            this->fun(idx + 1, digits);
            this->path[idx] = 'x';
            this->fun(idx + 1, digits);
            this->path[idx] = 'y';
            this->fun(idx + 1, digits);
            this->path[idx] = 'z';
            this->fun(idx + 1, digits);
        } else {

        }
    }


public:
    vector<string> letterCombinations(string digits) {
        int n = int(digits.length());
        this->res.clear();
        this->path.clear();
        if (0 == n) {
            return this->res;
        }
        for (int i = 0; i < n; ++i) {
            this->path.push_back(0);
        }
        this->fun(0, digits);
        return this->res;
    }
};

int main() {
    Solution *solution = new Solution();
    solution->letterCombinations("23");
    delete solution;
    return 0;
}
