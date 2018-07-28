//
// Created by 王阳 on 2018/7/28.
//

#include "header.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = int(matrix.size());
        if (0 == m) {
            return false;
        }
        int n = int(matrix[0].size());
        if (0 == n) {
            return false;
        }
        int i = 0;
        int j = n - 1;
        while (i < m && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            } else if (target < matrix[i][j]) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
