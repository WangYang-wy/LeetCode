//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        bool ans = false;
        int n = int(nums.size());
        if (0 == n) {
            return ans;
        }

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                if (j - i + 1 >= 2) { // 索引满足要求。
                    if (0 == k) {
                        if (0 == sum) {
                            return true;
                        } else {
                            continue;
                        }
                    } else {
                        if (0 == sum % k) {
                            return true;
                        }
                    }
                } else {
                    continue;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    std::cout << solution->checkSubarraySum(a, 0) << std::endl;
    delete solution;
    return 0;
}
