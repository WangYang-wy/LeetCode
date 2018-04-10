//
// Created by 王阳 on 2018/4/10.
//

#include "header.h"

/**
 * Reverse bits of a given 32 bits unsigned integer.
 * For example, given input 43261596 (represented in binary as
 * 00000010100101000001111010011100), return 964176192 (represented in binary
 * as 00111001011110000010100101000000).
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * Related problem: Reverse Integer
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            uint32_t tmp = (n & (1 << i)) >> i; // 从右往左开始提取bit.
//            printf("%u\n", tmp);
            res ^= tmp << (31 - i); // 提取之后，重新移动(31 - i)位。
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%d\n", solution->reverseBits(43261596));
    return 0;
}