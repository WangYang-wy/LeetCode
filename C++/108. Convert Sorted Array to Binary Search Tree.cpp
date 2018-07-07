//
// Created by 王阳 on 2018/3/29.
//

/*
 * Given an array where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more than 1.
 */

#include "header.h"

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) { // 如果是空，则返回。
            return NULL;
        }
        vector<int> less;
        vector<int> more;
        int middle = int(nums.size() / 2);

        for (int i = 0; i < middle; i++) {
            less.push_back(nums[i]);
        }

        for (int i = middle + 1; i < nums.size(); i++) {
            more.push_back(nums[i]);
        }

        TreeNode *p = new TreeNode(nums[middle]); // 递归的方式。
        p->left = sortedArrayToBST(less);
        p->right = sortedArrayToBST(more);
        return p;
    }
};

int main() {
    Solution *solution = new Solution();
//    printf("%d\n", solution)
    return 0;
}