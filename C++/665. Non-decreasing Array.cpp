//
// Created by 王阳 on 2018/5/11.
//

#include "header.h"

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        bool modified = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) { // 存在减少。
                if (modified) { // 已经修改过了。
                    return false;
                }
                (i - 2 < 0 || nums[i - 2] <= nums[i]) ? nums[i - 1] = nums[i] : nums[i] = nums[i - 1];
                modified = true;
            }
        }
        return true;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}