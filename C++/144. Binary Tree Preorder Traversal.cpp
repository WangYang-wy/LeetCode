//
// Created by 王阳 on 2018/7/30.
//

#include "header.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> ans;

public:
    vector<int> preorderTraversal(TreeNode *root) {
        this->ans.clear();
        stack<TreeNode *> s;
        if (nullptr == root) {
            return this->ans;
        }
        s.push(root);
        while (!s.empty()) {
            TreeNode *tmp = s.top();
            s.pop();
            this->ans.push_back(tmp->val);

            if (tmp->right) {
                s.push(tmp->right);
            }

            if (tmp->left) {
                s.push(tmp->left);
            }


        }
        return this->ans;
    }
};

int main() {
    return 0;
}
