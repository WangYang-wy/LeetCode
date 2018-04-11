//
// Created by 王阳 on 2018/4/11.
//

#include "header.h"

/**
 * Write a program to find the n-th ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
 */

/**
 * 参考博客：https://blog.csdn.net/sbitswc/article/details/48168159
 * 参考博客：https://www.cnblogs.com/njczy2010/p/5708377.html
 * 去构造一个丑数，而不是挨个去判断是否是丑数。
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n); // 预留n个位置。
        int index_2 = 0, index_3 = 0, index_5 = 0;
        int val_2 = 2, val_3 = 3, val_5 = 5;
        int i = 1;
        dp[0] = 1; // 第一个是1。
        for (; i < n; i++) {
            int val = min(val_2, min(val_3, val_5));
            if (val == val_2) {
                dp[i] = val_2;
                index_2++;
                val_2 = dp[index_2] * 2;
            }
            if (val == val_3) {
                dp[i] = val_3;
                index_3++;
                val_3 = dp[index_3] * 3;
            }
            if (val == val_5) {
                dp[i] = val_5;
                index_5++;
                val_5 = dp[index_5] * 5;
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}