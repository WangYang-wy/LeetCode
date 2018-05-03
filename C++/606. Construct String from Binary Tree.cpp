//
// Created by 王阳 on 2018/5/3.
//

#include "header.h"

/**
 * 参考博客：https://blog.csdn.net/connor_yang/article/details/76167633
 */

class Solution {
public:
    string tree2str(TreeNode *t) {
        if (t == NULL) return "";

        if (t->left == NULL && t->right == NULL) {
            return to_string(t->val);
        }

        if (t->left != NULL && t->right == NULL) {
            return to_string(t->val) + "(" + tree2str(t->left) + ")";
        }

        if (t->left == NULL && t->right != NULL) {
            return to_string(t->val) + "()" + "(" + tree2str(t->right) + ")";
        }

        return to_string(t->val) + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}