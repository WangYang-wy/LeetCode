//
// Created by 王阳 on 2018/7/28.
//

#include "header.h"

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        int n = int(A.size());
        vector<vector<int>> res;
        vector<int> tmp;
        res.clear();
        if (0 == n) {
            return res;
        }
        int m = int(A[0].size());
        for (int j = 0; j < m; ++j) {
            tmp.clear();
            for (int i = 0; i < n; ++i) {
                tmp.push_back(A[i][j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    return 0;
}
