//
// Created by 王阳 on 2018/8/20.
//

#include "header.h"
/**
 * 参考博客：https://blog.csdn.net/u012501459/article/details/46822007
 */
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int pivot = nums[0];
        int left = 0;
        int right = nums.size() - 1;
        while (true) {
            int pos = partion(nums, left, right);
            if (pos == k - 1) {
                return nums[pos];
            }
            if (pos < k - 1) {
                left = pos + 1;
            } else {
                right = pos - 1;
            }
        }
    }

    int partion(vector<int> &nums, int begin, int end) {
        int left = begin + 1;
        int right = end;
        while (left <= right) {
            if (nums[left] < nums[begin] && nums[right] > nums[begin]) {
                swap(nums[left], nums[right]);
            }
            if (nums[left] >= nums[begin]) {
                left++;
            }
            if (nums[right] <= nums[begin]) {
                right--;
            }
        }
        swap(nums[begin], nums[right]);
        return right;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    for (auto x:nums) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << solution->findKthLargest(nums, 1) << std::endl;
    return 0;
}
