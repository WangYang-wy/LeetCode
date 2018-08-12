//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n = int(B.length());
        int m = int(A.length());
        int res = INT_MAX;
        vector<int> begin;
        // 寻找 B 的第一个字母在 A 中的索引。
        for (int i = 0; i < m; ++i) {
            if (A[i] == B[0]) {
                begin.push_back(i);
            }
        }

        if (0 == begin.size()) {
            return -1;
        }

        for (int i = 0; i < begin.size(); ++i) { //遍历所有初始集合。
            bool flag = true;
            int times = 1;
            int index = 0;
            for (int j = 0; j < n; ++j) { // 便利所有 B 的字母。
                if (B[j] == A[begin[i] + index]) {
                    ++index;
                    if (begin[i] + index >= m) {
                        index = (begin[i] + index) % m - begin[i]; // 模除索引。
                        if (j != n - 1) {
                            times++;
                        }
                    }
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res = min(res, times);
            }
        }
        if (INT_MAX == res) {
            return -1;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->repeatedStringMatch("a", "aa") << std::endl;
    return 0;
}