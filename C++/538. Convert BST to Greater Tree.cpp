//
// Created by 王阳 on 2018/5/1.
//

#include "header.h"

class Solution {
private:
    vector<int> vec;
public:
    TreeNode *convertBST(TreeNode *root) {
        if (NULL == root) {
            return NULL;
        }
        pre_order(root);
        add(root);
        return root;
    }

    void add(TreeNode *root) {
        if (NULL == root) {
            return;
        }

        add(root->left);
        root->val += greater(root->val);
        // std::cout << "val = " << root->val << ", greater = " << greater(root->val) << std::endl;
        add(root->right);
    }

    // 对BST进行先序遍历，得到升序的数组。
    void pre_order(TreeNode *root) {
        if (NULL == root) {
            return;
        }

        pre_order(root->left);
        this->vec.push_back(root->val);
        pre_order(root->right);
    }

    // 在升序的数组中，求最大
    int greater(int target) {
        int sum = 0;
        for (int i = 0; i < this->vec.size(); i++) {
            if (vec[i] > target) {
                sum += vec[i];
            }
        }
        return sum;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}