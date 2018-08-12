//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        TreeNode *res;
        if (nullptr == t1 && nullptr == t2) {
            return nullptr;
        }

        if (nullptr == t1) {
            return t2;
        }

        if (nullptr == t2) {
            return t1;
        }

        res = new TreeNode(t1->val + t2->val);
        res->left = this->mergeTrees(t1->left, t2->left);
        res->right = this->mergeTrees(t1->right, t2->right);
        return res;
    }
};

int main() {
    return 0;
}