//
// Created by 王阳 on 2018/5/11.
//

#include "header.h"

/**
 * You are given a binary tree in which each node contains an integer value.
 * Find the number of paths that sum to a given value.
 * The path does not need to start or end at the root or a leaf,
 * but it must go downwards (traveling only from parent nodes to child nodes).
 * The tree has no more than 1,000 nodes and the values are
 * in the range -1,000,000 to 1,000,000.
 */

class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (NULL == root) {
            return 0;
        }
        int count = 0;
        vector<TreeNode *> vec;
        findPath(root, sum, 0, count, vec);
        return count;
    }

    void findPath(TreeNode *node, int sum, int curSum, int &res, vector<TreeNode *> &vec) {
        if (NULL == node) {
            return;
        }

        curSum += node->val; // 累计值。
        if (curSum == sum) {
            res++;
        }

        vec.push_back(node); // 将当前结点，加入栈中。

        int tmp = curSum;
        for (int i = 0; i < vec.size(); i++) {
            tmp -= vec[i]->val; // 依次减去从头开始的值。
            if (tmp == sum) {
                res++;
            }
        }

        findPath(node->left, sum, curSum, res, vec);
        findPath(node->right, sum, curSum, res, vec);

        vec.pop_back();
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}
