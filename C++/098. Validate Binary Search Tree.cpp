//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
private:
    vector<int> array;
public:
    bool isValidBST(TreeNode *root) {
        if (nullptr == root) { // 当前结点为空。
            return true;
        }
        this->in_order(root);

        int n = int(this->array.size());
        for (int i = 1; i < n; i++) {
            if (this->array[i] <= this->array[i - 1]) {
                return false;
            }
        }
        return true;
    }

    void in_order(TreeNode *root) {
        if (nullptr == root) {
            return;
        }
        in_order(root->left);
        this->array.push_back(root->val);
        in_order(root->right);
    }
};

int main() {
    return 0;
}
