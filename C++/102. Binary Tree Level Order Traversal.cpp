//
// Created by 王阳 on 2018/4/18.
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
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (NULL == root) {
            return res;
        }
        queue<pair<TreeNode *, int>> q;
        vector<pair<TreeNode *, int>> vec;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *tmp = q.front().first;
            int level = q.front().second;
            vec.push_back(make_pair(tmp, level));
            q.pop();
            if (tmp->left) {
                q.push(make_pair(tmp->left, level + 1));
                // vec.push_back(make_pair(tmp->left, level + 1));
            }

            if (tmp->right) {
                q.push(make_pair(tmp->right, level + 1));
                // vec.push_back(make_pair(tmp->right, level + 1));
            }
        }

        int n = int(vec.size());
        std::cout << vec.size() << std::endl;

        vector<int> temp;
        int max_layer = ceil(log2(n));
        for (int j = 0; j < n; j++) {

            // std::cout << vec[i].second << ":" << vec[i].first->val << std::endl;

            temp.clear();
            for (int i = 0; i < n; i++) {
//                res[vec[i].second].push_back(vec[i].first->val);
                if (j == vec[i].second) {
                    temp.push_back(vec[i].first->val);
                }
            }

            if (temp.size())
                res.push_back(temp);
        }

        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}