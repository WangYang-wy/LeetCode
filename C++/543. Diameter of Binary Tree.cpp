//
// Created by 王阳 on 2018/5/24.
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

/**
 * 参考博客：https://blog.csdn.net/zhyh1435589631/article/details/65939602
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }

        int left_part = 0, right_part = 0, left_height = 0, right_height = 0;

        if (root->left) { // 如果根节点有左子树。
            // 左子树的直径。
            left_part = diameterOfBinaryTree(root->left);
            left_height = getDeepLength(root->left);
        }

        if (root->right) { // 如果根节点有右子树。
            // 右子树的直径。
            right_part = diameterOfBinaryTree(root->right);
            right_height = getDeepLength(root->right);
        }

        // left_height + right_height：左子树的深度+右子树的深度。
        // 以及，左子树的最大半径与右子树的最大半径。
        return max(max(left_part, right_part), left_height + right_height);
    }

    /**
     * 得到二叉树的深度。
     * @param root 根节点。
     * @return 深度值。
     */
    int getDeepLength(TreeNode *root) {
        if (NULL == root) {
            return 0;
        } else {
            return 1 + max(getDeepLength(root->left), getDeepLength(root->right));
        }
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}