//
// Created by 王阳 on 2018/4/10.
//

/**
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 */
#include "header.h"

/**
 * 参考博客：https://blog.csdn.net/sunao2002002/article/details/45674029
 * 由于，出现两次，使用位运算，N xor N = 0.亦或方法，最后只剩下那个出现一次的数。
 */
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int length = int(nums.size());
        int res = 0;
        for (int item : nums) {
            res ^= item;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(1);
    printf("%d.\n", solution->singleNumber(a));
    return 0;
}