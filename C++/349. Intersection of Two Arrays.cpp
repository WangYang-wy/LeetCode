//
// Created by 王阳 on 2018/4/17.
//
/**
 * Given two arrays, write a function to compute their intersection.
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 */
#include "header.h"

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        int n_1 = int(nums1.size());
        int n_2 = int(nums2.size());
        vector<int> res;
        for (int i = 0; i < n_1; i++) {
            for (int j = 0; j < n_2; j++) {
                if (nums1[i] == nums2[j] && !isContains(res, nums1[i])) {
                    res.push_back(nums1[i]);
                }
            }
        }
        return res;
    }

    bool isContains(vector<int> &vec, int target) {
        for (auto x:vec) {
            if (target == x) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}