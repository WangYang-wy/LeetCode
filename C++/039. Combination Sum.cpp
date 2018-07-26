//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    int path_len = 0;
public:
    void fun(int idx, vector<int> &candidates, int target) {
        int n = int(candidates.size());
        if (0 == target) { // 已经找完了。
            vector<int> tmp;
            for (int i = 0; i < this->path_len; ++i) {
                tmp.push_back(this->path[i]);
            }
            this->res.push_back(tmp);
            return;
        }

        if (0 > target || idx >= n) {
            return;
        }

        // used.
        this->path[path_len] = candidates[idx];
        this->path_len++;
        fun(idx, candidates, target - candidates[idx]);
        this->path_len--;

        // no use.
        fun(idx + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        int n = int(candidates.size());
        this->res.clear();
        this->path.clear();
        this->path.reserve(100);
        this->fun(0, candidates, target);
        return this->res;
    }
};

int main() {
    return 0;
}
