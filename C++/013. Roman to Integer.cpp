//
// Created by 王阳 on 2018/4/11.
//
/**
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */
#include "header.h"

class Solution {
public:
    int romanToInt(string s) {
        int n = int(s.length());
        if (0 == n) {
            return 0;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'I':
                    res += 1;
                    break;
                case 'V':
                    res += 5;
                    break;
                case 'X':
                    res += 10;
                    break;
                case 'L':
                    res += 50;
                    break;
                case 'C':
                    res += 100;
                    break;
                case 'D':
                    res += 500;
                    break;
                case 'M':
                    res += 1000;
                    break;
            }
        }

        for (int i = 1; i < n; i++) {
            if ((s[i] == 'V' || s[i] == 'X') && s[i - 1] == 'I') {
                res -= 1 + 1;
            }

            if ((s[i] == 'L' || s[i] == 'C') && s[i - 1] == 'X') {
                res -= 10 + 10;
            }

            if ((s[i] == 'D' || s[i] == 'M') && s[i - 1] == 'C') {
                res -= 100 + 100;
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->romanToInt("IV") << std::endl;
    std::cout << solution->romanToInt("CD") << std::endl;
    std::cout << solution->romanToInt("CM") << std::endl;
    return 0;
}