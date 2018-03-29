//
// Created by 王阳 on 2018/3/29.
//

/*
 * Given a binary tree, return all root-to-leaf paths.
 * For example, given the following binary tree:
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> *s = new vector<TreeNode *>();
    vector<string> res;

    /**
     * dfs.
     * @param root 树。
     * @return 字符串数组。
     */
    vector<string> binaryTreePaths(TreeNode *root) {
        if (NULL == root) {
            return res;
        }

        dfs(root);

        printf("print res\n");
        print_res();
        return res;
    }

    void dfs(TreeNode *tmp) {
        if (tmp != NULL) {
            s->push_back(tmp);
        } else {
            return;
        }

        printf("tmp-val = %d\n", tmp->val);
        if (tmp->left == NULL && tmp->right == NULL) { // 当前为叶节点。
            printf("leaf node.\n");
            print_stack(s);
            printf("\n");
            s->pop_back();
            return;
        }
        dfs(tmp->left);
        dfs(tmp->right);
        s->pop_back();
    }

    void print_stack(vector<TreeNode *> *p) {
        printf("print stack begin.\n");
        for (int i = 0; i < p->size(); i++) {
            printf("%d\n", ((*p)[i])->val);
        }
        printf("print stack end.\n");
        string tmp;
        int i = 0;
        for (i = 0; i < p->size() - 1; i++) {
            tmp = tmp + to_string(((*p)[i])->val) + "->";
        }
        tmp = tmp + to_string(((*p)[i])->val);
        res.push_back(tmp);
//
    }

    void print_res() {
        for (int i = 0; i < res.size(); i++) {
            printf("%s\n", res[i].c_str());
        }
    }
};

int main() {
    Solution *solution = new Solution();
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
//    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);

    p->right = new TreeNode(3);
    solution->binaryTreePaths(p);
    return 0;
}