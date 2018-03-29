//
// Created by 王阳 on 2018/3/29.
//
#include <iostream>
#include <vector>

using namespace std;

/*
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has
 * (also known as the Hamming weight).
 * For example, the 32-bit integer ’11' has binary representation
 * 00000000000000000000000000001011, so the function should return 3.
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (uint32_t i = 0; i < 32; i++) {
            uint32_t tmp = uint32_t(1 << i);
            printf("tmp = %u\n", tmp);
            if ((n & tmp) == tmp) {
                printf("n & tmp = %u\n", n & tmp);
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%d\n", solution->hammingWeight(11));
    return 0;
}