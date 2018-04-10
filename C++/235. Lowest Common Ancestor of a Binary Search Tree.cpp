//
// Created by 王阳 on 2018/4/10.
//

/**
 * Given a binary search tree (BST), find the lowest common ancestor (LCA)
 * of two given nodes in the BST. According to the definition of LCA on Wikipedia:
 * “The lowest common ancestor is defined between two nodes v and w as the lowest
 * node in T that has both v and w as descendants (where we allow a node to be a
 * descendant of itself).”
 */
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        string str_p = findPath(root, p);
        string str_q = findPath(root, q);
        TreeNode *res = root;
        int index = -1;
        for (int i = 0; true; i++) {
            if (str_p[i] != str_q[i]) {
                index = i - 1;
                break;
            }
        }

        if (-1 == index) {
            return res;
        } else {
            for (int i = 0; i <= index; i++) {
                if ('0' == str_p[i]) {
                    res = res->left;
                } else {
                    res = res->right;
                }
            }
            return res;
        };
    }

    string findPath(TreeNode *root, TreeNode *p) {
        TreeNode *find = root;
        string str;
        while (NULL != find && NULL != p && find->val != p->val) {
            if (p->val <= find->val) {
                find = find->left;
                str = str + to_string(0);
            } else {
                find = find->right;
                str = str + to_string(1);
            }
        }
        return str;
    }
};

int main() {
    Solution *solution = new Solution();
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    TreeNode *q = root->left->left->left = new TreeNode(1);

    TreeNode *p = root->left->right = new TreeNode(4);

    root->right = new TreeNode(6);
    printf("%d\n", solution->lowestCommonAncestor(root, p, q)->val);
    printf("p path = %s\n", solution->findPath(root, p).c_str());
    printf("q path = %s\n", solution->findPath(root, q).c_str());
    return 0;
}