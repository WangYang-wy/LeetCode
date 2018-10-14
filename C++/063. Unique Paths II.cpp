//
// Created by 王阳 on 2018/10/14.
//

#include "header.h"

class Solution {
private:
    int m;
    int n;
    int my_count = 0;

    // x 竖直坐标，y 水平坐标。
    void search(int x, int y, vector<vector<int>> &obstacleGrid) {
        if (x >= this->m || y >= this->n || 1 == obstacleGrid[x][y]) {
            // 越界或者障碍。
            return;
        }

        if (x == this->m - 1 && y == this->n - 1) {
            this->my_count++;
            return;
        }

        this->search(x + 1, y, obstacleGrid);
        this->search(x, y + 1, obstacleGrid);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        this->m = int(obstacleGrid.size());
        if (0 == this->m) {
            return 0;
        }

        this->n = int(obstacleGrid[0].size());
        if (0 == this->n) {
            return 0;
        }
        vector<vector<int>> paths;
        vector<int> tmp;
        for (int i = 0; i < m; ++i) {
            tmp.clear();
            for (int j = 0; j < n; ++j) {
                tmp.push_back(0);
            }
            paths.push_back(tmp);
        }


        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] != 1) {
                paths[i][0] = 1;
            } else {
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] != 1) {
                paths[0][i] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (0 == obstacleGrid[i][j]) {
                    paths[i][j] = 0;
                } else {
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                }
            }
        }

        return paths[m - 1][n - 1];
    }

    int uniquePathsWithObstacles_TLE(vector<vector<int>> &obstacleGrid) {
        this->m = int(obstacleGrid.size());
        if (0 == this->m) {
            return 0;
        }

        this->n = int(obstacleGrid[0].size());
        if (0 == this->n) {
            return 0;
        }
        this->search(0, 0, obstacleGrid);
        return this->my_count;
    }
};

int main() {
    return 0;
}