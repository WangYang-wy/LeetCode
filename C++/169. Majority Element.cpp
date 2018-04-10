//
// Created by 王阳 on 2018/4/10.
//
/**
 * Given an array of size n, find the majority element.
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */

#include "header.h"

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int index = int(nums.size()) / 2;
        sort(nums.begin(), nums.end());
        return nums[index];
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(3);
    a.push_back(3);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    printf("%d.\n", solution->majorityElement(a));
    return 0;
}