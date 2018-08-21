//
// Created by 王阳 on 2018/8/21.
//

#include "header.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> st;
    TreeNode *head;
public:
    BSTIterator(TreeNode *root) {
        while (root != nullptr) {
            if (root) {
                st.push(root);
                root = root->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !this->st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = st.top();
        st.pop();
        int ret = node->val;

        node = node->right;
        while (node) {
            st.push(node);
            node = node->left;
        }
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    return 0;
}