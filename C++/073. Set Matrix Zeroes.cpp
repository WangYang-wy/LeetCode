//
// Created by 王阳 on 2018/7/31.
//

#include "header.h"

class Solution {
private:
    vector<bool> row;
    vector<bool> col;
public:
    void setZeroes(vector<vector<int>> &matrix) {
        this->row.clear();
        this->col.clear();
        int m = int(matrix.size());
        if (0 == m) {
            return;
        }
        int n = int(matrix[0].size());
        for (int i = 0; i < m; ++i) {
            this->row.push_back(false);
        }
        for (int i = 0; i < n; ++i) {
            this->col.push_back(false);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == matrix[i][j]) {
                    this->row[i] = true;
                    this->col[j] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (this->row[i] || this->col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};

int main() {
    return 0;
}
