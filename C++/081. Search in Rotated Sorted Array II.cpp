//
// Created by 王阳 on 2018/7/31.
//

#include "header.h"

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = int(nums.size());
        for (int i = 0; i < n; ++i) {
            if (target == nums[i]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
