//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        } else {
            int left = this->get_left_height(root);
            int right = this->get_right_height(root);

            if (left == right) {
                return (1 << right) - 1;
            } else {
                return this->countNodes(root->left) + this->countNodes(root->right) + 1;
            }
        }
    }

    int get_left_height(TreeNode *root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int get_right_height(TreeNode *root) {
        int height = 0;
        while (root) {
            height++;
            root = root->right;
        }
        return height;
    }
};

int main() {
    return 0;
}