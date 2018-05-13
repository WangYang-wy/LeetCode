//
// Created by 王阳 on 2018/5/13.
//

#include "header.h"

/**
 * Given an array of integers nums sorted in ascending order, find the starting and
 * ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 */

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res;
        int n = int(nums.size());
        int first = binarySearch(nums, target);
        int last = binarySearch(nums, target + 1) - 1;
        // 这个不一定找到准确的值，只要比target大的最小的那个就可以了。
        if (first == n || nums[first] != target) {
            res.push_back(-1);
            res.push_back(-1);
        } else {
            res.push_back(first);
            res.push_back(max(first, last));
        }
        return res;
    }

    int binarySearch(vector<int> &nums, int target) {
        int n = int(nums.size());
        int l = 0;
        int h = n;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] >= target) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}