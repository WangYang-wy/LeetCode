//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = int(nums.size());
        int count = 0;
        for (int i = 0; i < n ; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                if (k == sum) {
                    count++;
                }
            }
        }
        return count;
    }
};


int main() {
    return 0;
}
