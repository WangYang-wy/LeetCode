//
// Created by 王阳 on 2018/3/29.
//

/*
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 * Example:
 * Given num = 16, return true. Given num = 5, return false.
 * Follow up: Could you solve it without loops/recursion?
 * Credits:
 * Special thanks to @yukuairoy for adding this problem and creating all test cases.
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0 && int(log10(num) / log10(4)) - log10(num) / log10(4) == 0);
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%d\n", solution->isPowerOfFour(2));
//    for (int i = 0; i < 19; i++) {
//        printf("4^%d = %d\n", i, int(pow(4, i)));
//    }
    return 0;
}