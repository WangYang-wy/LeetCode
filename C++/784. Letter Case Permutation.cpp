//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
private:
    vector<string> res;
    vector<char> path;

    void fun(int idx, string S) {
        int n = int(S.length());
        if (idx >= n) {
            string tmp;
            for (int i = 0; i < n; ++i) {
                tmp += this->path[i];
            }
            this->res.push_back(tmp);
            return;
        }

        if (S[idx] >= '0' && S[idx] <= '9') { // 数字。
            this->path[idx] = S[idx];
            this->fun(idx + 1, S);
        } else if (S[idx] >= 'a' && S[idx] <= 'z') { // 小写字母。
            // 变换。
            this->path[idx] = (S[idx] - ('a' - 'A'));
            this->fun(idx + 1, S);
            // 不变换。
            this->path[idx] = S[idx];
            this->fun(idx + 1, S);
        } else if (S[idx] >= 'A' && S[idx] <= 'Z') { // 大写字母。
            // 变换。
            this->path[idx] = (S[idx] + ('a' - 'A'));
            this->fun(idx + 1, S);
            // 不变换。
            this->path[idx] = S[idx];
            this->fun(idx + 1, S);
        }
    }

public:
    vector<string> letterCasePermutation(string S) {
        res.clear();
        this->path.reserve(S.length());
        this->fun(0, S);
        return this->res;
    }
};

int main() {
    Solution *solution = new Solution();
    solution->letterCasePermutation("a1b2");
    delete solution;
    return 0;
}
