//
// Created by 王阳 on 2018/3/30.
//

#include "header.h"

/**
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 x is guaranteed to be a non-negative integer.
 */
class Solution {
public:
    int mySqrt(int x) {
        return int(sqrt(x));
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%d\n", solution->mySqrt(2147483647));
    return 0;
}