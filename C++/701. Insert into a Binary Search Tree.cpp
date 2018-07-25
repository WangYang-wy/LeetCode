//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        TreeNode *res = root;
        while (true) {
            if (val < root->val) { // 向左走。
                if (nullptr == root->left) {
                    root->left = new TreeNode(val);
                    break;
                }
                root = root->left;
            } else if (val >= root->val) { // 向右走。
                if (nullptr == root->right) {
                    root->right = new TreeNode(val);
                    break;
                }
                root = root->right;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
