//
// Created by 王阳 on 2018/3/29.
//

/*
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 */

#include "header.h"

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        if (target <= nums[0]) {
            return 0;
        }

        if (target > nums[nums.size() - 1]) {
            return int(nums.size());
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < target && nums[i] >= target) {
                return i;
            }
        }
        return int(nums.size() - 1);
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(6);
    printf("%d\n", solution->searchInsert(a, 5));
    return 0;
}