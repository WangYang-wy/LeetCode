//
// Created by 王阳 on 2018/5/9.
//

#include "header.h"

/**
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 * some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = int(nums.size());
        vector<bool> flag;

        for (int i = 0; i < n; i++) {
            flag.push_back(true);
        }

        for (int i = 0; i < n; i++) {
            if (flag[nums[i] - 1]) { // 如果该值以前没有出现过，那么以该值为索引的数变为负数，这里需要-1。
//                std::cout << "i = " << i << ", " << nums[i] << std::endl;
                flag[nums[i] - 1] = false;
            }
        }

        // 一次遍历后，所有出现过的值，以该值为索引的值为负数。

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (flag[i]) {
//                std::cout << "> i = " << i << ", " << nums[i] << std::endl;
                res.push_back(1 + i);
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    std::cout << nums.size() << std::endl;
    solution->findDisappearedNumbers(nums);
    delete solution;
    return 0;
}