//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int index = -1;
        int n = int(nums.size());
        for (int i = 0; i < n; ++i) {
            if (target == nums[i]) {
                index = i;
                break;
            }
        }
        return index;
    }
};

int main() {
    return 0;
}
