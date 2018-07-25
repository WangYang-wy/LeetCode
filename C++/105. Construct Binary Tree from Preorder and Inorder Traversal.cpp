//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int pre_len = int(preorder.size());
        int in_len = int(inorder.size());
        return buildTree(preorder, 0, pre_len, inorder, 0, in_len);
    }

    TreeNode *buildTree(vector<int> &preorder, int pre_start, int pre_end,
                        vector<int> &inorder, int in_start, int in_end) {
        if (in_start >= in_end) {
            return nullptr;
        }

        // 先从前序结点来说，
        int i = in_start;
        // 从先序遍历中，找到根节点，然后在中序结果中找到位置。
        while (i < in_end) {
            if (preorder[pre_start] == inorder[i]) {
                break;
            }
            ++i;
        }
        // i 为中序遍历中的根节点位置。

        TreeNode *root = new TreeNode(preorder[pre_start]); // 构造根节点。
        int left_len = i - in_start; // 左子树的结点个数。
        root->left = buildTree(preorder, pre_start + 1, pre_start + left_len + 1, inorder, in_start, i);
        root->right = buildTree(preorder, pre_start + left_len + 1, pre_end, inorder, i + 1, in_end);
        return root;
    }
};

int main() {
    return 0;
}
