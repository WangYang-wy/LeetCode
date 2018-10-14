//
// Created by 王阳 on 2018/10/14.
//

#include "header.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (0 == m || 0 == n) {
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
            paths[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            paths[0][i] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
        return paths[m - 1][n - 1];
    }
};