//
// Created by 王阳 on 2018/5/3.
//

#include "header.h"

class Solution {
public:
    // O(n).
    int maximumProduct(vector<int> &nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (auto &i: nums) {
            if (i > max1) {
                max3 = max2, max2 = max1, max1 = i;
            } else if (i > max2) {
                max3 = max2, max2 = i;
            } else if (i > max3) {
                max3 = i;
            }

            if (i < min1) {
                min2 = min1, min1 = i;
            } else if (i < min2) {
                min2 = i;
            }
        }

        return max(max1 * max2 * max3, max1 * min1 * min2);
    }

    // O(nlogn).
    int maximumProduct_lower(vector<int> &nums) {
        int n = int(nums.size());
        sort(nums.begin(), nums.end());
        int index = -1;
        for (int i = 0; i < n; i++) {
            if ((0 == nums[i])
                || ((i < n - 1) && (nums[i] < 0) && (nums[i + 1] > 0))
                || (i == n - 1) && (nums[i] < 0)) {
                index = i;
                break;
            }
        }

        // 保证index之后，都是正数，如果index=-1，那么说明全是正数。

        int detla = n - index - 1; // 数组中，含有正数的个数。

        int last_3 = nums[n - 1] * nums[n - 2] * nums[n - 3];

        int first_2 = nums[0] * nums[1];

        if (-1 == index) { // 全是正数。
            return last_3;
        } else if (detla <= 0) { // 全是负数。
            return last_3;
        } else if (1 == detla) { // 只有一个正数。
            return nums[n - 1] * first_2;
        } else {
            return last_3 > first_2 * nums[n - 1] ? last_3 : first_2 * nums[n - 1];
        }
    }

    int maximumProduct_tle(vector<int> &nums) {
        int n = int(nums.size());
        int product = INT_MIN;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int temp_product = nums[i] * nums[j] * nums[k];
                    if (temp_product > product) {
                        product = temp_product;
                    }
                }
            }
        }
        return product;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}