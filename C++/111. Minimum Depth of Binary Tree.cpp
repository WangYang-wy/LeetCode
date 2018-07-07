//
// Created by 王阳 on 2018/3/29.
//

/*
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from
 * the root node down to the nearest leaf node.
 */

#include "header.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    queue<TreeNode *> *q = new queue<TreeNode *>();
    vector<int> *s = new vector<int>();

    int minDepth(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }
        int res = INT_MAX;
        q->push(root); // 根节点入队。
        bfs(root, 0);

        for (int i = 0; i < s->size(); i++) {
            printf("i = %d\n", (*s)[i]);
            res = min(res, (*s)[i]);
        }

        return res;
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }

    void bfs(TreeNode *tmp, int step) {
        if (NULL != tmp) {
            step = step + 1;
//            printf("tmp->val = %d\n", tmp->val);
//            printf("step = %d\n", step);
        } else {
            return;
        }

        if (tmp->right == NULL && tmp->left == NULL) { // 找到叶节点。
            s->push_back(step);
//            printf("leaf node.\n");
            return;
        }

        bfs(tmp->left, step);
        bfs(tmp->right, step);

        if (tmp->left != NULL) {
            q->push(tmp->left);
        }

        if (tmp->right != NULL) {
            q->push(tmp->right);
        }
    }
};

int main() {
    Solution *solution = new Solution();
    TreeNode *t = new TreeNode(1);
//    t->left = new TreeNode(10);
//    t->left->left = new TreeNode(100);
//    t->left->left->left = new TreeNode(3);
//    t->left->left->left->left = new TreeNode(4);

    t->right = new TreeNode(2);
    printf("res = %d\n", solution->minDepth(t));
    return 0;
}