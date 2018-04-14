//
// Created by 王阳 on 2018/4/14.
//

#include "header.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> res;
public:
    // 思路，用一个vector来存储小于等于自己的数字，由于是BST，那采用DFS来遍历。
    bool findTarget(TreeNode *root, int k) {
        if (NULL == root) {
            return false;
        }
        PreOrder(root);

        int size = int(this->res.size());
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (k == this->res[i] + this->res[j]) {
                    return true;
                }

                if (this->res[j] > k - this->res[i]) {
                    break;
                }
            }
        }

    }

    // 用先序遍历，来产生一个有序的数组。
    void PreOrder(TreeNode *root) {
        if (NULL == root) {
            return;
        }
        PreOrder(root->left);
        this->res.push_back(root->val);
        PreOrder(root->right);
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}