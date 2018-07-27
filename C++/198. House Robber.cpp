//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
private:
    vector<int> computed; // 备忘录，计算过后就不再计算。
public:
    int solve(int idx, vector<int> &nums) {
        if (idx < 0) {
            return 0;
        }

        if (this->computed[idx] >= 0) {
            return this->computed[idx];
        }

        this->computed[idx] = max(nums[idx] + this->solve(idx - 2, nums), this->solve(idx - 1, nums));

        // 重叠子问题。
        return this->computed[idx];
    }

    // 迭代法。
    int rob_iter(vector<int> &nums) {
        int n = int(nums.size());
        if (0 == n) {
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            this->computed.push_back(-1); // 假设没计算过，就设置为 -1。
        }

        this->computed[0] = 0;
        this->computed[1] = max(nums[0], nums[1]);

        for (int idx = 2; idx < n; ++idx) {
            this->computed[idx] = max(nums[idx] + this->computed[idx - 2], this->computed[idx - 1]);
        }
        return this->computed[n - 1];
    }

    // dp.
    int rob_dp(vector<int> &nums) {
        int n = int(nums.size());
        for (int i = 0; i < n; ++i) {
            this->computed.push_back(-1); // 假设没计算过，就设置为 -1。
        }
        return this->solve(n - 1, nums);
    }
};

int main() {
    return 0;
}
