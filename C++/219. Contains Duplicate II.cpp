//
// Created by 王阳 on 2018/4/17.
//

#include "header.h"
/**
 * 参考博客：https://www.cnblogs.com/grandyang/p/4539680.html
 * 思路：我们首先需要一个哈希表，来记录每个数字和其坐标的映射，
 * 然后我们需要一个变量d来记录第一次出现重复数字的坐标差。
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
                return true;
            } else {
                m[nums[i]] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    a.push_back(9);
    std::cout << solution->containsNearbyDuplicate(a, 3) << std::endl;
    return 0;
}