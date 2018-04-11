//
// Created by 王阳 on 2018/4/11.
//

#include "header.h"

/**
 * Given an integer, write an algorithm to convert it to hexadecimal.
 * For negative integer, two’s complement method is used.
 * Note:
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is zero,
 * it is represented by a single zero character '0'; otherwise, the first character
 * in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed integer.
 * You must not use any method provided by the library which converts/formats the number
 * to hex directly.
 */

class Solution {
public:
    string toHex(int num) {
        string res;
        if (num > 0) {
            while (num > 0) {
                res = get_hex_digit(num % 16) + res;
                num /= 16;
            }
            return res;
        } else if (num < 0) {
            unsigned num_tmp = unsigned(num) + 4294967295 + 1;
//            std::cout << num_tmp << std::endl;
            while (num_tmp > 0) {
                res = get_hex_digit(num_tmp % 16) + res;
                num_tmp /= 16;
            }
            return res;
        } else {
            return "0";
        }
    }

    char get_hex_digit(int i) {
        switch (i) {
            case 0:
                return '0';
            case 1:
                return '1';
            case 2:
                return '2';
            case 3:
                return '3';
            case 4:
                return '4';
            case 5:
                return '5';
            case 6:
                return '6';
            case 7:
                return '7';
            case 8:
                return '8';
            case 9:
                return '9';
            case 10:
                return 'a';
            case 11:
                return 'b';
            case 12:
                return 'c';
            case 13:
                return 'd';
            case 14:
                return 'e';
            case 15:
                return 'f';
            default:
                return 0;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->toHex(16) << std::endl;
    std::cout << solution->toHex(17) << std::endl;
    std::cout << solution->toHex(0) << std::endl;
    std::cout << solution->toHex(-1) << std::endl;
    std::cout << solution->toHex(-2) << std::endl;
    return 0;
}

