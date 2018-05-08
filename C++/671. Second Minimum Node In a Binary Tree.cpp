//
// Created by 王阳 on 2018/5/8.
//

#include "header.h"

/**
 * Given a non-empty special binary tree consisting of nodes with the non-negative value,
 * where each node in this tree has exactly two or zero sub-node. If the node has two
 * sub-nodes, then this node's value is the smaller value among its two sub-nodes.
 * Given such a binary tree, you need to output the second minimum value in the set
 * made of all the nodes' value in the whole tree.
 * If no such second minimum value exists, output -1 instead.
 */

class Solution {
private:
    vector<int> res;
public:
    int findSecondMinimumValue(TreeNode *root) {
        int value = -1;
        pre_order(root);
        sort(this->res.begin(), this->res.end());

        int n = int(res.size());
        int min = res[0]; // 假设第一个最小。
        for (int i = 1; i < n; i++) {
            if (this->res[i] > min) {
                value = this->res[i];
                break;
            }
        }

        return value;
    }

    void pre_order(TreeNode *root) {
        if (NULL == root) {
            return;
        }
        pre_order(root->left);
        this->res.push_back(root->val);
        pre_order(root->right);
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}