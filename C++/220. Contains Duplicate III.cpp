//
// Created by 王阳 on 2018/4/4.
//

/*
 * Given an array of integers, find out whether there are two distinct
 * indices i and j in the array such that the absolute difference between
 * nums[i] and nums[j] is at most t and the absolute difference
 * between i and j is at most k.
 */


#include "header.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.size() < 2) {
            return false;
        }

        vector<pair<long, int>> value;

        for (int i = 0; i < nums.size(); ++i) {
            value.push_back(pair<long, int>(nums[i], i)); // 存取值和索引。
        }
        sort(value.begin(), value.end()); // 排序。

        for (int i = int(nums.size() - 1); i >= 1; --i) { // 从右往左扫描。
            for (int j = i - 1; j >= 0; --j) { // 从右往左扫描。
                if (value[i].first - value[j].first > t) { // 排序之后可以有效降低比较时间。
                    break;
                } else if (abs(value[i].second - value[j].second) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(-3);
//    a.push_back(3);
    a.push_back(3);
//    a.push_back(3);
//    a.push_back(3);
    printf("size = %d\n", a.size());

    for (int i = 0; i < a.size(); i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("%d\n", solution->containsNearbyAlmostDuplicate(a, 2, 4));

    return 0;
}