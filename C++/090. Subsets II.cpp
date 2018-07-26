//
// Created by 王阳 on 2018/7/26.
//

#include "header.h"

class Solution {
private:
    vector<vector<int>> res;
    vector<bool> visited;
public:
    void fun(int idx, vector<int> &nums) {
        int n = int(nums.size());
        if (idx >= n) {
            vector<int> tmp;
            for (int i = 0; i < n; ++i) {
                if (this->visited[i]) {
                    tmp.push_back(nums[i]);
                }
            }
            this->res.push_back(tmp);
            return;
        }

        // 对于值相当的一段，只能前一段取，后一段不取，不能间隔地取，会制造重复。
        if (idx > 0 && nums[idx - 1] == nums[idx] && !this->visited[idx - 1]) {
            this->visited[idx] = false;
            this->fun(idx + 1, nums);
        } else {
            this->visited[idx] = true;
            this->fun(idx + 1, nums);
            this->visited[idx] = false;
            this->fun(idx + 1, nums);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        this->res.clear();
        this->visited.clear();
        int n = int(nums.size());
        this->visited.reserve(n);
        sort(nums.begin(), nums.end());
        this->fun(0, nums);
        return this->res;
    }
};

int main() {
    return 0;
}
