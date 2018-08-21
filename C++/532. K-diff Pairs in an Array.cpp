//
// Created by 王阳 on 2018/8/21.
//

#include "header.h"

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        int count = 0;
        int n = int(nums.size());
        sort(nums.begin(), nums.end());
        int first = 0;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (k == nums[j] - nums[i] && first != nums[i] && last != nums[j]) {
                    first = nums[i];
                    last = nums[j];
                    count++;
                }

                if (k < nums[j] - nums[i]) {
                    break;
                }
            }
        }
        return count;
    }
};

int main() {
    return 0;
}