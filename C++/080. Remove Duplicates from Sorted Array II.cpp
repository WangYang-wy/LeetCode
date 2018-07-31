//
// Created by 王阳 on 2018/7/31.
//

#include "header.h"

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        const int n = nums.size();
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
                continue;
            nums[index++] = nums[i];
        }
        return index;
    }
};

int main() {
    return 0;
}
