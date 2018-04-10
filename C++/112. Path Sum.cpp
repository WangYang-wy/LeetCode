//
// Created by 王阳 on 2018/4/10.
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
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // 是一个dfs的过程。
        if (NULL == root) {
            return false;
//        } else if (sum == root->val && NULL == root->right && NULL == root->left) {
        } else if (NULL == root->right && NULL == root->left && sum == root->val) {
            // 要保证是根节点，先判断是否为空结点，效率要高一些！
            return true;
        }

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}