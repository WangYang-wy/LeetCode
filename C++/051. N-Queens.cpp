//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
private:
    vector<vector<string>> res;
    vector<bool> line;
    vector<int> path;
    vector<bool> plus;
    vector<bool> mins;

    void dfs(int idx, int n) {
        if (idx >= n) {
            // record.
            vector<string> chess;
            for (int i = 0; i < n; i++) {
                string tmp;
                for (int j = 0; j < n; ++j) {
                    if (j == this->path[i]) {
                        tmp += 'Q';
                    } else {
                        tmp += '.';
                    }
                }
                chess.push_back(tmp);
            }
            this->res.push_back(chess);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!this->line[i] && !this->plus[idx + i] && !this->mins[idx - i + n - 1]) {
                this->path[idx] = i;
                this->line[i] = true;
                this->plus[idx + i] = true;
                this->mins[idx - i + n - 1] = true;
                this->dfs(idx + 1, n);
                this->line[i] = false;
                this->plus[idx + i] = false;
                this->mins[idx - i + n - 1] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        this->res.clear();
        this->line.clear();
        this->path.clear();
        for (int i = 0;i < n;++i) {
            this->path.push_back(0);
            this->line.push_back(false);
        }

        for (int i = 0;i < 2 * n;++i) {
            this->plus.push_back(false);
            this->mins.push_back(false);
        }

        this->dfs(0, n);
        return this->res;
    }
};

int main() {
    Solution *solution = new Solution();
    auto x = solution->solveNQueens(5);
    for (auto i : x) {
        for (auto j : i) {
            std::cout << j << std::endl;
        }
    }
    x = solution->solveNQueens(6);
    for (auto i : x) {
        for (auto j : i) {
            std::cout << j << std::endl;
        }
    }
    delete solution;
    return 0;
}
