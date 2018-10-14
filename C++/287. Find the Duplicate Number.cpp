//
// Created by 王阳 on 2018/8/21.
//

#include "header.h"

class Solution {
public:
    /**
     * 参考博客：https://segmentfault.com/a/1190000003817671
     */
    int findDuplicate(vector<int> &nums) {
        int n = int(nums.size());
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mid) {
                    count++;
                }
            }

            if (count > mid) { // 说明在左边。
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    return 0;
}