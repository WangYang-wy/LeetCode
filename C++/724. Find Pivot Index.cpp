//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int index = -1; // 初始化不存在。
        int n = int(nums.size());
        if (n < 2) {
            return index;
        }
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += nums[i];
        }

        int left = 0;
        int right = sum;

        for (int i = 0; i < n; i++) {
            if (left == right) {
                index = i;
                break;
            }
            left += nums[i];
            right -= nums[i + 1];
        }
        return index;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
//    [1, 7, 3, 6, 5, 6]
    a.push_back(-1);
    a.push_back(-1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    std::cout << solution->pivotIndex(a) << std::endl;
    delete solution;
    return 0;
}
