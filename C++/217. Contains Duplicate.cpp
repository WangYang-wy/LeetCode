//
// Created by 王阳 on 2018/4/17.
//

#include "header.h"

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = int(nums.size());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}