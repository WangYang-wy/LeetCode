//
// Created by 王阳 on 2018/5/3.
//

#include "header.h"

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
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
            return nums[n - 1] * nums[0] * nums[1];
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