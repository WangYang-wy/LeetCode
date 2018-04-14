//
// Created by 王阳 on 2018/4/14.
//

#include "header.h"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int original_r = nums.size();
        int original_c = nums[0].size();
        if (r == original_r && c >= original_c) {
            return nums;
        }

        if (r * c > original_r * original_c) {
            return nums;
        }

        vector<int> temp;
        for (int i = 0; i < original_r; i++) {
            for (int j = 0; j < original_c; j++) {
                temp.push_back(nums[i][j]);
            }
        }

        vector<vector<int>> res;
        int size = original_r * original_c;
        for (int i = 0; i < size; i++) {
            vector<int> temp_inner;
            for (int j = 0; j < c; j++) {
                temp_inner.push_back(temp[i]);
                i++;
            }
            i--;
            res.push_back(temp_inner);
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}