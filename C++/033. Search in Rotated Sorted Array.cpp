//
// Created by 王阳 on 2018/7/31.
//

#include "header.h"

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = int(nums.size());
        int left = 0;
        int right = n - 1; // [L, R)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (nums[left] <= nums[mid]) { // pivot 在右边。
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else { // pivot 在左边。
                if (nums[mid] < target && target <= nums[right - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}
