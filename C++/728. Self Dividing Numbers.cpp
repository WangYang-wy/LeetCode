//
// Created by 王阳 on 2018/5/3.
//

#include "header.h"

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            int temp = i;
            while (temp != 0 && temp % 10 != 0) {
                if (i % (temp % 10) != 0) {
                    break;
                }
                temp = temp / 10;
            }
            if (temp == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    auto x = solution->selfDividingNumbers(1, 22);
    for (auto item:x) {
        std::cout << item << std::endl;
    }
    delete solution;
    return 0;
}