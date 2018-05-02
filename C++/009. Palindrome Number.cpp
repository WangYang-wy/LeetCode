//
// Created by 王阳 on 2018/5/2.
//

#include "header.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int record = x;
        int inverse = 0;
        while (x) {
            inverse = inverse * 10 + x % 10;
            x = x / 10;
        }

        return inverse == record;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->isPalindrome(121) << std::endl;
    delete solution;
    return 0;
}