//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        unordered_map<int, int> a;
        for (auto x:nums) { // 统计词频。
            a[x]++;
        }

        int max_value = -1;
        int len = int(nums.size());
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] > max_value) {
                max_value = a[i];
            }
        }
        vector<int> max_value_list;
        for (int i = 0; i < a.size(); ++i) {
            if (max_value == a[i]) {
                max_value_list.push_back(i);
            }
        }
        int res_len = INT_MAX;
        for (auto x:max_value_list) {
            vector<int> index;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == x) {
                    index.push_back(i);
                }
            }
            int max_index = index[index.size() - 1];
            int min_index = index[0];

            res_len = min(max_index - min_index + 1, res_len);
            index.clear();
        }
        return res_len;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {47, 47, 72, 47, 72, 47, 79, 47, 12, 92, 13, 47, 47, 83, 33, 15, 18, 47, 47, 47, 47, 64, 47, 65,
                        47, 47, 47, 47, 70, 47, 47, 55, 47, 15, 60, 47, 47, 47, 47, 47, 46, 30, 58, 59, 47, 47, 47, 47,
                        47, 90, 64, 37, 20, 47, 100, 84, 47, 47, 47, 47, 47, 89, 47, 36, 47, 60, 47, 18, 47, 34, 47, 47,
                        47, 47, 47, 22, 47, 54, 30, 11, 47, 47, 86, 47, 55, 40, 49, 34, 19, 67, 16, 47, 36, 47, 41, 19,
                        80, 47, 47, 27};
    std::cout << solution->findShortestSubArray(nums) << std::endl;
    return 0;
}