//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int in_len = int(inorder.size());
        int post_len = int(postorder.size());
        return buildTree(inorder, 0, in_len, postorder, 0, post_len);
    }

    TreeNode *buildTree(vector<int> &inorder, int in_start, int in_end,
                        vector<int> &postorder, int post_start, int post_end) {
        if (in_start >= in_end) {
            return nullptr;
        }

        int root_ptr = postorder[post_end - 1];
        int index = in_start;
        while (index < in_end) {
            if (root_ptr == inorder[index]) {
                break;
            }
            ++index;
        }

        int left_len = index - in_start;
        TreeNode *root = new TreeNode(root_ptr); // 后序遍历的最后一个元素为根节点。
        root->left = buildTree(inorder, in_start, index, postorder, post_start, post_start + left_len);
        root->right = buildTree(inorder, index + 1, in_end, postorder,
                                post_start + left_len, post_end - 1);
        return root;
    }
};

int main() {
    return 0;
}
