//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visited;
public:
    void fun(int idx, int n, int k) {
        if (0 == k) { // 还能选 0 个。
            this->res.push_back(this->path);
            return;
        }

        for (int i = idx + 1; i <= n; ++i) {
            this->path[k - 1] = i;
            this->fun(i, n, k - 1);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        res.clear();
        path.clear();
        visited.clear();
        for (int i = 0; i < n; ++i) {
            this->visited.push_back(false);
            if (i < k) {
                this->path.push_back(0);
            }
        }
        this->fun(0, n, k);
        return res;
    }
};

int main() {
    return 0;
}
