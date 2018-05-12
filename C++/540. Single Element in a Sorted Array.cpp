//
// Created by 王阳 on 2018/5/12.
//

#include "header.h"

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = int(nums.size());
        int l = 0;
        int h = n - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (1 == m % 2) { // 如果m是奇数。
                m--;
            }

            if (nums[m] == nums[m + 1]) {
                l = m + 2;
            } else {
                h = m;
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