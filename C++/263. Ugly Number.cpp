//
// Created by 王阳 on 2018/4/9.
//
/**
 * Write a program to check whether a given number is an ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 * Note:
 *      1 is typically treated as an ugly number.
 *      Input is within the 32-bit signed integer range.
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */
#include "header.h"

class Solution {
public:
    bool isUgly(int num) {
        if (1 == num) {
            return true;
        }

        if (num <= 0) {
            return false;
        }

        while (1 != num) {
            if (0 == num % 2) {
                num = num / 2;
            } else if (0 == num % 3) {
                num = num / 3;
            } else if (0 == num % 5) {
                num = num / 5;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}