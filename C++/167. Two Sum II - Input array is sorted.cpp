//
// Created by 王阳 on 2018/4/14.
//

#include "header.h"

/**
 * Given an array of integers that is already sorted in ascending order,
 * find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that
 * they add up to the target, where index1 must be less than index2.
 * Please note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you
 * may not use the same element twice.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        for (int i = 0; i < numbers.size() - 1; i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (target == numbers[i] + numbers[j]) {
                    res.push_back(i + 1);
                    res.push_back(j + 1);
                    return res;
                }

                if (numbers[j] > target - numbers[i]) {
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(-1);
    a.push_back(0);
    vector<int> b = solution->twoSum(a, -1);
    for (auto x:b) {
        std::cout << x << std::endl;
    }
    return 0;
}