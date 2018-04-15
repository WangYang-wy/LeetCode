//
// Created by 王阳 on 2018/4/15.
//

#include "header.h"

/*
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 */
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int n = int(s.length());
        for (int i = 0; i < n; i++) {
            int digit = getDigit(s[i]);
            res = res * 26 + digit;
        }
        return res;
    }

    int getDigit(char c) {
        return c - 64;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->titleToNumber("AA") << std::endl;
    return 0;
}