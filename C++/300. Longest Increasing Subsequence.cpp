//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
private:
    vector<int> path;
    vector<int> f;
public:
    int fun(int idx, vector<int> &nums) {
        if (idx < 0) {
            return 0;
        }

        if (f[idx] > 0) {
            return this->f[idx];
        }

        int ans = 0;
        for (int i = 0; i < idx; i++) {
            if (nums[idx] > nums[i]) {
                ans = max(ans, this->fun(i, nums));
            }
        }
        f[idx] = ans + 1;
        return ans + 1;
    }

    int lengthOfLIS(vector<int> &nums) {
        int n = int(nums.size());
        for (int i = 0; i < 10000; ++i) {
            this->f.push_back(0);
        }
        for (int i = 0; i < n; i++) {
            this->path.push_back(nums[i]);
        }
        this->path.push_back(INT_MAX);
        n++;

        return this->fun(n - 1, this->path) - 1; // 减到那个加入的最大数。
    }
};

int main() {
    return 0;
}
