//
// Created by 王阳 on 2018/8/12.
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
    vector<int> postorderTraversal(TreeNode *root) {
        this->ans.clear();

        if (nullptr == root) {
            return this->ans;
        }

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *tmp = s.top();
            s.pop();

            if (tmp->left) {
                s.push(tmp->left);
            }

            if (tmp->right) {
                s.push(tmp->right);
            }

            this->ans.push_back(tmp->val);
        }
        reverse(this->ans.end(), this->ans.begin());
        return this->ans;
    }
};

int main() {
    return 0;
}