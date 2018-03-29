//
// Created by 王阳 on 2018/3/29.
//

/*
 * Given an integer, write a function to determine if it is a power of two.
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && int(log10(n) / log10(2)) - log10(n) / log10(2) == 0);
    }
};

int main() {
    Solution *solution = new Solution();
//    printf("%d\n", solution)
    return 0;
}