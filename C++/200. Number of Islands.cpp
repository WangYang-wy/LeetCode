//
// Created by 王阳 on 2018/7/28.
//

#include "header.h"

class Solution {
private:
    queue<pair<int, int>> q;

    void flood_fill(int x, int y, vector<vector<char>> &grid) {
        int m = int(grid.size());
        int n = int(grid[0].size());
        while (!this->q.empty()) {
            auto x = q.front();
            q.pop();
            int i = x.first;
            int j = x.second;
            if (i >= 1 && i < m && j >= 0 && j < n) { // 向上。
                if ('1' == grid[i - 1][j]) {
                    this->q.push(make_pair(i - 1, j));
                    grid[i - 1][j] = '0';
                }
            }

            if (i >= 0 && i < m && j >= 1 && j < n) { // 向左。
                if ('1' == grid[i][j - 1]) {
                    this->q.push(make_pair(i, j - 1));
                    grid[i][j - 1] = '0';
                }
            }

            if (i >= 0 && i < m && j >= 0 && j < n - 1) { // 向右。
                if ('1' == grid[i][j + 1]) {
                    this->q.push(make_pair(i, j + 1));
                    grid[i][j + 1] = '0';
                }
            }

            if (i >= 0 && i < m - 1 && j >= 0 && j < n) { // 向下。
                if ('1' == grid[i + 1][j]) {
                    this->q.push(make_pair(i + 1, j));
                    grid[i + 1][j] = '0';
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int m = int(grid.size());
        if (0 == m) {
            return 0;
        }
        int ans = 0;
        int n = int(grid[0].size());
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('1' == grid[i][j]) {
                    q.push(make_pair(i, j));
                    this->flood_fill(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
