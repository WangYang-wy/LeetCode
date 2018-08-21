//
// Created by 王阳 on 2018/8/21.
//

#include "header.h"

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        unordered_map<int, int> map;
        int n = int(nums.size());
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                map[nums[i]] = 1;
            }
        }
        int res = 1;
        while (map.find(res) != map.end()) {
            res++;
        }
        return res;
    }
};

int main() {
    return 0;
}