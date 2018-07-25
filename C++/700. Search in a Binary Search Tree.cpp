//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        while (true) {
            if (nullptr == root) {
                return nullptr;
            } else if (val == root->val) {
                return root;
            } else if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
};

int main() {
    return 0;
}
