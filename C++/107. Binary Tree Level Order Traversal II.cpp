//
// Created by 王阳 on 2018/4/10.
//
/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes'
 * values. (ie, from left to right, level by level from leaf to root).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
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
    // 自己写的。
    vector<vector<int>> levelOrderBottom_my(TreeNode *root) {
        vector<vector<int>> res;
        int max_layer = 0;
        if (NULL == root) {
            return res;
        }
        queue<pair<TreeNode *, int>> q;
        queue<pair<TreeNode *, int>> p;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode *, int> tmp = q.front();
            q.pop();

            p.push(tmp);

            if (NULL != tmp.first->left) {
                q.push(make_pair(tmp.first->left, tmp.second + 1));
            }

            if (NULL != tmp.first->right) {
                q.push(make_pair(tmp.first->right, tmp.second + 1));
            }

//            printf("当前结点的值：%d, ", tmp.first->val);
//            printf("当前结点的层级：%d。\n", tmp.second);
            max_layer = tmp.second + 1;
        }
//        for (int i = 0; i < max_layer; i++) {
//            res.push_back(*new vector<int>);
//        }
//        printf("最大层级：%d.\n", max_layer);
        pair<TreeNode *, int> tmp;
        vector<int> a;
        int layer = 0;
        while (!p.empty()) {
            tmp = p.front();
            p.pop();
            printf("val = %d, and layer = %d. \n", tmp.first->val, tmp.second);

            if (layer == tmp.second) { // 在当前层。
                a.push_back(tmp.first->val);
            } else { // 下一层。
                layer++;
                res.insert(res.begin(), a);
                a.clear();
                a.push_back(tmp.first->val);
            }
//            res[tmp.second].insert(res[tmp.second].begin(), tmp.first->val);
//            res[tmp.second].push_back(tmp.first->val);
        }
        res.insert(res.begin(), a);
//        printf("%d\n", int(res.size()));
//
        for (auto item : res) {
            for (auto x:item) {
                printf("x = %d\n", x);
            }
        }
        return res;
    }

    // 算法改进，在bfs的时候，当前队列里的元素个数，就是当前层的元素个数。
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (NULL == root) {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> layer;
            int size = int(q.size());
            for (int i = 0; i < size; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                layer.push_back(tmp->val);
                if (tmp->left) {
                    q.push(tmp->left);
                }

                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
            res.push_back(layer);
        }
        reverse(res.begin(), res.end());
        for (auto item : res) {
            for (auto x : item) {
                printf("%d\n", x);
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    TreeNode *p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(7);
    solution->levelOrderBottom(p);
    return 0;
}