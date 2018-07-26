//
// Created by 王阳 on 2018/7/26.
//

#include "header.h"

class Solution {
public:
    bool guess(long mid, vector<int> &nums, int m) {
        int sum = 0;
        int used = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum + nums[i] > mid) {
                used++;
                sum = nums[i];
                if (nums[i] > mid) { // 根本放不下。
                    return false;
                }
            } else {
                sum += nums[i];
            }
        }
        // 最后有一个 sum 有一个不为 0。
        return used < m;
    }

    // 最大和比较小。
    int splitArray(vector<int> &nums, int m) {
        long ans = 0;
        long n = int(nums.size());
        if (n == m) {
            int res = nums[0];
            for (int i = 1; i < n; i++) {
                if (res < nums[i]) {
                    res = nums[i];
                }
            }
            return res;
        }
        long right = 1; // 左闭右开。
        for (int i = 0; i < n; i++) {
            right += nums[i];
        }

        long left = 0;

        while (left < right) {
            long mid = left + (right - left) / 2;
            if (this->guess(mid, nums, m)) {
                ans = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return int(ans);
    }
};

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2147483647);
    Solution *solution = new Solution();
    std::cout << solution->splitArray(a, 2) << std::endl;
    return 0;
}
