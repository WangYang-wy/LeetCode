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
public:
    // 解法：先作镜像翻转，然后挨个结点比较。
    bool isSymmetric(TreeNode *root) {
        isMirror(root, root);
    }

    bool isMirror(TreeNode *root1, TreeNode *root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }

        if (root1 == NULL || root2 == NULL) {
            return false;
        }
        return (root1->val == root2->val) && (isMirror(root1->left, root2->right)) &&
               (isMirror(root1->right, root1->left));
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}