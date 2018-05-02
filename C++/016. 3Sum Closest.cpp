//
// Created by 王阳 on 2018/5/2.
//

#include "header.h"

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int n = int(nums.size());
        int abs_sum = INT_MAX;
        int a, b, c;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < abs_sum) {
                        abs_sum = abs(sum - target);
                        a = nums[i];
                        b = nums[j];
                        c = nums[k];
                    }
                }
            }
        }
        return a + b + c;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(-1);
    a.push_back(2);
    a.push_back(1);
    a.push_back(-4);
    std::cout << solution->threeSumClosest(a, 1) << std::endl;
    return 0;
}