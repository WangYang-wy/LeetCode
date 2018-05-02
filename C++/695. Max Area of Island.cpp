//
// Created by 王阳 on 2018/5/2.
//

#include "header.h"

/**
 * 参考博客：https://blog.csdn.net/u011809767/article/details/78179243
 * dfs.
 */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 0;
        }
        if (grid[i][j]) {
            grid[i][j] = 0;
            return 1 + dfs(grid, i, j + 1) + dfs(grid, i + 1, j)
                   + dfs(grid, i, j - 1) + dfs(grid, i - 1, j);
        }
        return 0;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}