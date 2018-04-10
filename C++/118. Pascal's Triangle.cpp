//
// Created by 王阳 on 2018/4/10.
//

#include "header.h"

class Solution {
public:
    // 递归方法。
    vector<vector<int>> generate_r(int numRows) {
        vector<vector<int>> res;
        if (numRows < 1) {
            return res;
        } else if (1 == numRows) {
            vector<int> a;
            a.push_back(1);
            res.push_back(a);
        } else {
            res = generate_r(numRows - 1);
            vector<int> a;
            for (int i = 0; i < numRows; i++) {
                a.push_back(c(i, numRows - 1));
            }
            res.push_back(a);
        }
        return res;
    }

    /**
     * 计算组合数：C_n^m
     * @param m 上标
     * @param n 下标
     * @return 组合数。
     */
    int c(int m, int n) {
        int res = 1;
        if (0 == m) { ;
        } else {
            for (int i = 0; i < m; i++) {
                res *= n - i;
                res /= i + 1;
            }
        };
        return res;
    }

    // 二重循环的方法。
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows < 1) {
            return res;
        } else {
            for (int i = 0; i < numRows; i++) {
                vector<int> a;
                for (int j = 0; j < numRows; j++) {
                    a.push_back(c(j, i - 1));
                }
                res.push_back(a);
            }
        }
        return res;
    }
};


int main() {
    Solution *solution = new Solution();
    printf("%d\n", solution->c(1, 4));
    return 0;
}
