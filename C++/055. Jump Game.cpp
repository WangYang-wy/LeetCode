//
// Created by 王阳 on 2018/7/31.
//

#include "header.h"

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = int(nums.size());
        vector<bool> reach(n, false);
        reach[0] = true;
        for (int i = 0; i < n; ++i) {
            if (reach[i]) { // 如果可达。
                for (int index = 0; index < nums[i]; ++index) {
                    reach[i + 1 + index] = true;
                    if (reach[n - 1]) {
                        return true;
                    }
                }
            }
        }
        return reach[n - 1];
    }
};

int main() {
    return 0;
}
