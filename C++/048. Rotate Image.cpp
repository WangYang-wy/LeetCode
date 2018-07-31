//
// Created by 王阳 on 2018/7/31.
//

#include "header.h"

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = int(matrix.size());
        if (0 == n) {
            return;
        }
        // 上下翻转。
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmp = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        // 主对角线翻转，转置。
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        return;
    }
};

int main() {
    return 0;
}
