//
// Created by 王阳 on 2018/3/29.
//

/*
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the depth of the two subtrees of every
 * node never differ by more than 1.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {

        if (NULL == root) {
            return true;
        }

        int diffDepth = getDepth(root->left) - getDepth(root->right);
        return diffDepth >= -1 && diffDepth <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int getDepth(TreeNode *root) {
        if (NULL == root) {
            return 0;
        } else {
            return 1 + max(getDepth(root->right), getDepth(root->left));
        }
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};


int main() {
    Solution *solution = new Solution();
    TreeNode *p = new TreeNode(1);

    p->left = new TreeNode(2);
    p->left->left = new TreeNode(3);
    p->left->left->left = new TreeNode(4);

    p->right = new TreeNode(2);
    p->right->right = new TreeNode(3);
    p->right->right->right = new TreeNode(4);
    printf("%d\n", solution->isBalanced(p));
    return 0;
}