//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int n = int(nums.size());
        if (0 == n) {
            return 0;
        }
        int count = 1;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                bool flag = true;
                for (int k = i; k < j; ++k) {
                    if (nums[k] >= nums[k + 1]) { // 如果不增加。
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    count = max(count, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(2);
    a.push_back(2);
    a.push_back(2);
    a.push_back(2);
    a.push_back(2);
//    a.push_back(1);
//    a.push_back(3);
//    a.push_back(5);
//    a.push_back(4);
//    a.push_back(7);
    std::cout << solution->findLengthOfLCIS(a) << std::endl;
    delete solution;
    return 0;
}
