//
// Created by 王阳 on 2018/4/10.
//
/**
 * Given an integer, return its base 7 string representation.
 */

#include "header.h"

class Solution {
public:
    string convertToBase7(int num) {
        string res;
        if (num < 0) {
            num = -num;
            while (num != 0) {
                res = to_string(num % 7) + res;
                num = num / 7;
            }
            return '-' + res;
        } else if (num > 0){
            while (num != 0) {
                res = to_string(num % 7) + res;
                num = num / 7;
            }
            return res;
        } else {
            return "0";
        }
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%s\n", solution->convertToBase7(-7).c_str());
    printf("%s\n", solution->convertToBase7(100).c_str());
    printf("%s\n", solution->convertToBase7(7).c_str());
    return 0;
}