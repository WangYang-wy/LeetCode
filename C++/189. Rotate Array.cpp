//
// Created by 王阳 on 2018/4/10.
//

#include "header.h"

/**
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7]
 * is rotated to [5,6,7,1,2,3,4].
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways
 * to solve this problem.
 * [show hint]
 * Hint:
 * Could you do it in-place with O(1) extra space?
 * Related problem: Reverse Words in a String II
 * Credits:
 * Special thanks to @Freezen for adding this problem and creating all test cases.
 */

/**
 * 参考博客：https://leetcode.com/problems/rotate-array/description/
 * 主要问题在于理解，为何k是负数？模k同余。
 */
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = int(nums.size());
        k = k % n;
        if (k == 0)
            return;

        reverseString(nums, 0, n - k - 1);
        reverseString(nums, n - k, n - 1);
        reverseString(nums, 0, n - 1);
    }

    void reverseString(vector<int> &nums, int from, int to) {
        while (from < to) {
            int temp = nums[from];
            nums[from++] = nums[to];
            nums[to--] = temp;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}