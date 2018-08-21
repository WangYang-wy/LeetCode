//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode *> st;
        ret.clear();

        while (root != nullptr || !st.empty()) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                ret.push_back(root->val);
                root = root->right;
            }
        }
        return ret;
    }
};

int main() {
    return 0;
}
