//
// Created by 王阳 on 2018/10/14.
//

#include "header.h"

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = int(grid.size());
        if (0 == m) {
            return 0;
        }
        int n = int(grid[0].size());
        if (0 == n) {
            return 0;
        }

        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};