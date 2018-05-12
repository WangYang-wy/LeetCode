//
// Created by 王阳 on 2018/5/12.
//

#include "header.h"

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = int(nums.size());
        int l = 0;
        int h = n - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (nums[m] <= nums[h]) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};


int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}