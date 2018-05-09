//
// Created by 王阳 on 2018/5/9.
//

#include "header.h"

class Solution {
private:
    vector<int> res;
public:
    int getMinimumDifference(TreeNode *root) {
        pre_order(root);
        int n = int(this->res.size());
        int min = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            int diff = abs(this->res[i] - this->res[i + 1]);
            if (diff < min) {
                min = diff;
            }
        }
        return min;
    }

    void pre_order(TreeNode *root) {
        if (NULL == root) {
            return;
        }
        pre_order(root->left);
        this->res.push_back(root->val);
        pre_order(root->right);
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}