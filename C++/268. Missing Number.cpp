//
// Created by 王阳 on 2018/4/11.
//

#include "header.h"

/**
 * 参考博客：https://www.cnblogs.com/yrbbest/p/5022828.html
 * 方法：1. 等差数列求和，然后依次减去各个数字，但是可能会溢出。
 * 方法：2. 位运算。
 */

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = int(nums.size());

        if (NULL == nums || n == 0) {
            return 0;
        }

        int res = n;
        for (int i = 0; i < n; i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}