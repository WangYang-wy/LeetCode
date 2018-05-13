//
// Created by 王阳 on 2018/5/8.
//

#include "header.h"

// Given a binary search tree, write a function kthSmallest to
// find the kth smallest element in it.

class Solution {
private:
    vector<int> res;
public:
    int kthSmallest(TreeNode *root, int k) {
        pre_order(root);
        int n = int(this->res.size());

        return this->res[k - 1];
        // 关于重复？
    }

    int pre_order(TreeNode *root) {
        if (NULL == root) {
            return NULL;
        }
        pre_order(root->left);
        this->res.push_back(root->val);
        pre_order(root->right);
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}
