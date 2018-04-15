//
// Created by 王阳 on 2018/4/15.
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
    vector<int> res;
public:
    // 使用中序遍历。
    int sumOfLeftLeaves(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }
        order(root);
        int sum = 0;
        for (int i = 0; i < this->res.size(); i++) {
            sum += this->res[i];
        }

        return sum;
    }

    // 中序遍历。
    void order(TreeNode *root) {
        if (NULL == root) {
            return;
        }
        order(root->left);
        if (root->left && root->left->left == NULL && root->left->right == NULL) {
            res.push_back(root->left->val);
        }
//        std::cout << root->val << std::endl;
        order(root->right);
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}