//
// Created by 王阳 on 2018/3/28.
//

/*
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root
 * node down to the farthest leaf node.
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 */

/**
 * Definition for a binary tree node.
 */

#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (NULL == root) {
            return 0;
        } else {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    return 0;
}