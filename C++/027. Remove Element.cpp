//
// Created by 王阳 on 2018/4/10.
//
/**
 * Given an array and a value, remove all instances of that value in-place and return
 * the new length. Do not allocate extra space for another array, you must do this by
 * modifying the input array in-place with O(1) extra memory. The order of elements can
 * be changed. It doesn't matter what you leave beyond the new length.
 */
#include "header.h"

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int length = int(nums.size());
        auto it = nums.begin();
        for (int i = length - 1; i >= 0; i--) {
            if (val == nums[i]) {
                nums.erase(it + i);
            }
        }
        return int(nums.size());
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}