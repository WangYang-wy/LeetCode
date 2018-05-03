//
// Created by 王阳 on 2018/5/3.
//

#include "header.h"

/**
 * Given an m * n matrix M initialized with all 0's and several update operations.
 * Operations are represented by a 2D array, and each operation is represented by
 * an array with two positive integers a and b, which means M[i][j] should be added
 * by one for all 0 <= i < a and 0 <= j < b.
 * You need to count and return the number of maximum integers in the matrix after
 * performing all the operations.
 */

class Solution {
public:
    // 计算重叠。
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        int minrow = INT_MAX, mincol = INT_MAX;
        for (int i = 0; i < ops.size(); i++) {
            minrow = min(minrow, ops[i][0]);
            mincol = min(mincol, ops[i][1]);
        }
        minrow = min(minrow, m);
        mincol = min(mincol, n);
        return minrow * mincol;
    }

    // 超时。
    int maxCount_tle(int m, int n, vector<vector<int>> &ops) {
        int count = 0;
        int max = -1;
        vector<vector<int>> M;
        // 初始化。
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                tmp.push_back(0);
            }
            M.push_back(tmp);
        }

        for (auto item:ops) {
            for (int i = 0; i < item[0]; i++) {
                for (int j = 0; j < item[1]; j++) {
                    M[i][j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] > max) {
                    max = M[i][j];
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (max == M[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}