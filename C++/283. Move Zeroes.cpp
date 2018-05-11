//
// Created by 王阳 on 2018/5/11.
//

#include "header.h"


class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int n = int(nums.size());
        int count = 0;
        auto it = nums.begin();
        for (int i = n - 1; i >= 0; i--) {
            if (0 == nums[i]) {
                count++;
                nums.erase(it + i); // 删除。
            }
        }

        for (int i = 0; i < count; i++) {
            nums.push_back(0);
        }
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}