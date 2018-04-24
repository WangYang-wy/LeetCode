//
// Created by 王阳 on 2018/4/24.
//

#include "header.h"
/**
 * You have a total of n coins that you want to form in a staircase shape,
 * where every k-th row must have exactly k coins.
 * Given n, find the total number of full staircase rows that can be formed.
 * n is a non-negative integer and fits within the range of a 32-bit signed integer.
 */

class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        int i = 1;
        while (n >= i) {
            n = n - i;
            i = i + 1;
            count++;
        }
        return count;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->arrangeCoins(8) << std::endl;
    return 0;
}