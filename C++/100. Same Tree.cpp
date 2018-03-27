//
// Created by 王阳 on 2018/3/27.
//

/*
 * Given two binary trees, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical and
 * the nodes have the same value.
 */

#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) { // 如果均为空，那么相同。
            return true;
        } else if (p != NULL && q != NULL) {    // 如果均不为空。
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }
};

int main() {
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    TreeNode *q = new TreeNode(1);
    q->right = new TreeNode(2);
    Solution *solution = new Solution();
    printf("%d\n", solution->isSameTree(p, q));
    return 0;
}