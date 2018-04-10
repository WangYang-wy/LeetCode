//
// Created by 王阳 on 2018/4/10.
//

#include "header.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if (rowIndex < 1) {
            return res;
        }
        for (int i = 0; i <= rowIndex; ++i) {
            res.push_back(c(i, rowIndex));
        }

        for (auto x : res) {
            std::cout << x << std::endl;
        }

        return res;
    }

    /**
     * 计算组合数C_n^m，这里需要换成long，由于可能会int类型32位溢出。
     */
    long c(int m, int n) {
        long res = 1;
        if (0 == m) { ;
        } else {
            for (int i = 0; i < m; i++) {
                res *= n - i;
                res /= i + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
//    int a = 155117520;
//    std::cout << a;

    solution->getRow(30);
    return 0;
}
