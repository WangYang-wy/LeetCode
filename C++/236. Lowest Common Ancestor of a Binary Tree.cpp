//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
public:
    // 一定一个在 LCA 的左边，一个在 LCA 的右边。
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if ((nullptr == root) || (root == p) || (root == q)) {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (nullptr != left && nullptr != right) {
            return root;
        } else {
            return (nullptr != left) ? left : right;
        }
    }
};

int main() {
    return 0;
}
