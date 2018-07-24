//
// Created by 王阳 on 2018/7/24.
//

#include "header.h"

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        int ans = INT_MIN;

        if (0 == n) {
            return 0;
        }

        if (1 == n) {
            return nums[0];
        }

        // 因为考虑到符号问题。
        int maxLast = nums[0]; // 记录乘到上个元素的最大乘积。
        int minLast = nums[0]; // 记录乘到上个元素的最小乘积。
        int maxCur; // 记录乘到当前元素的最大乘积。
        int minCur; // 记录乘到当前元素的最小乘积。
        int maxAll = nums[0]; // 记录全局最大的乘积。
        for (int i = 1; i < n; i++) {
            maxCur = max(nums[i], max(maxLast * nums[i], minLast * nums[i]));
            minCur = min(nums[i], min(maxLast * nums[i], minLast * nums[i]));
            maxLast = maxCur;
            minLast = minCur;
            maxAll = max(maxAll, maxCur);
        }

        return maxAll;
    }
};

int main() {
    return 0;
}