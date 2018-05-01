//
// Created by 王阳 on 2018/5/1.
//

#include "header.h"

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double sum = INT_MIN;
        int n = int(nums.size());
        for (int i = 0; i <= n - k; i++) {

            double sum_temp = 0.0;

            for (int j = 0; j < k; j++) {
                sum_temp += nums[j + i];
            }

            if (sum_temp > sum) {
                sum = sum_temp;
            }
        }
        return sum / k;
    }
};

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(12);
    a.push_back(-5);
    a.push_back(-6);
    a.push_back(50);
    a.push_back(3);
    Solution *solution = new Solution();
    std::cout << solution->findMaxAverage(a, 4) << std::endl;
    return 0;
}