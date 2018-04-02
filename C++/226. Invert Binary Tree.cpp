//
// Created by 王阳 on 2018/4/2.
//

#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

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
    TreeNode *invertTree(TreeNode *root) {
        if (NULL == root) {
            return NULL;
        } else {

            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;

            invertTree(root->right);
            invertTree(root->left);

            return root;
        }
    }
};

int main() {
    Solution *solution = new Solution();

    TreeNode *p = new TreeNode(1);

    p->right = new TreeNode(2);
    p->left = new TreeNode(2);

    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(3);
    p->right->right = new TreeNode(3);
    p->right->left = new TreeNode(3);

//    printf("%d\n", solution)
    return 0;
}