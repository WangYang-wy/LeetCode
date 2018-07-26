//
// Created by 王阳 on 2018/7/26.
//

#include "header.h"

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> visited; // 记录一下是否访问过了。
public:
    /**
     * 递归方法。
     * @param idx 搜索的位置。
     * @param nums
     */
    void fun(int idx, vector<int> &nums) {
        int n = int(nums.size());
        if (idx >= n) {
            // 在边界条件中，记录结果。
            res.push_back(path);
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (visited[i] == false) {
                path[idx] = nums[i];
                this->visited[i] = true;
                fun(idx + 1, nums);
                this->visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        this->res.clear();
        int n = int(nums.size());
        for (int i = 0; i < n; ++i) {
            this->visited.push_back(false);
            this->path.push_back(0);
        }
        this->fun(0, nums);
        return res;
    }
};

int main() {
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
//    a.push_back(2);
//    a.push_back(3);
    Solution *solution = new Solution();
    solution->permute(a);
    return 0;
}
