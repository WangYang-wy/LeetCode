//
// Created by 王阳 on 2018/4/18.
//

#include "header.h"

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        vector<vector<int>> res;
        int m = M.size();
        int n = M[0].size();
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                tmp.push_back(0);
            }
            res.push_back(tmp);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;
                for (int p = max(0, i - 1); p < min(m, i + 2); p++) {
                    for (int q = max(0, j - 1); q < min(n, j + 2); q++) {
                        sum += M[p][q];
                        count++;
                    }
                }
                res[i][j] = floor(sum / count);
            }
        }

        return res;
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<vector<int>> res;
    int m = 3;
    int n = 3;
    for (int i = 0; i < m; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            tmp.push_back(1);
        }
        res.push_back(tmp);
    }
    solution->imageSmoother(res);
    return 0;
}