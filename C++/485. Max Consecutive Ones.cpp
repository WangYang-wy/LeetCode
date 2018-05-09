//
// Created by 王阳 on 2018/5/9.
//

#include "header.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = int(nums.size());
        for (int i = 1; i < n; i++) {
            if (nums[i] != 0) {
                nums[i] += nums[i - 1];
            }
        }

        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}