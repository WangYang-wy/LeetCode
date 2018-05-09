//
// Created by 王阳 on 2018/5/9.
//

#include "header.h"

/**
 * Given an array of 2n integers, your task is to group these integers into n
 * pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of
 * min(ai, bi) for all i from 1 to n as large as possible.
 */

class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        int sum = 0;
        int n = int(nums.size());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2) {
            sum += (nums[i] < nums[i + 1] ? nums[i] : nums[i + 1]);
        }
        return sum;
    }};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}