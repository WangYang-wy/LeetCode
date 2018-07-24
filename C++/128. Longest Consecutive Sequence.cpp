//
// Created by 王阳 on 2018/7/24.
//

#include "header.h"

class Solution {
public:
    /**
     * 用hash表来解决这个问题，先初始化一个hash表，
     * 存储所有数组元素，然后遍历这个数组，
     * 对找到的数组元素，去搜索其相连的上下两个元素是否在hash表中，
     * 如果在， 删除相应元素并增加此次查找的数据长度，如果不在，从下一个元素出发查找。
     * @param nums 数组。
     * @return 最长连续子串长度。
     */
    int longestConsecutive(vector<int> &nums) {
        int n = nums.size();
        if (0 == n) {
            return 0;
        }
        unordered_set<int> my_set(nums.begin(), nums.end());
        int res = 1;
        for (int n : nums) {
            if (my_set.find(n) == my_set.end()) {
                continue;
            }
            my_set.erase(n);
            int prev = n - 1;
            int next = n + 1;
            while (my_set.find(prev) != my_set.end()) {
                my_set.erase(prev--);
            }

            while (my_set.find(next) != my_set.end()) {
                my_set.erase(next++);
            }

            res = max(res, next - prev - 1);
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}
