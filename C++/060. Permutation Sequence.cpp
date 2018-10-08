//
// Created by 王阳 on 2018/10/8.
//
#include "header.h"

class Solution {
private:
    int step_to = 0;
    int N = 0;
    int step = 0;
    bool flag = false;
    vector<bool> visited;
    vector<int> path;

    void search(int idx) {
        if (this->flag) {
            return;
        }

        if (idx == N) {
            // record.
            this->step++;
            if (this->step_to <= this->step) { // 搜索到了。
                this->flag = true;
                return;
            }
            return;
        }

        for (int i = 0; i < this->N; ++i) {
            if (!this->flag && !this->visited[i]) {
                this->visited[i] = true;
                this->path[idx] = i + 1;
                this->search(idx + 1);
                this->visited[i] = false;
            }
        }
    }

public:
    string getPermutation(int n, int k) {
        this->step_to = k;
        this->N = n;
        this->visited.clear();
        this->path.clear();

        for (int i = 0; i < n; ++i) {
            this->visited.push_back(false);
            this->path.push_back(0);
        }

        this->search(0);

        string res;
        for (auto x:this->path) {
            res += to_string(x);
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->getPermutation(3, 3) << std::endl;
    delete solution;
    return 0;
}