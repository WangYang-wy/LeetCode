//
// Created by 王阳 on 2018/5/11.
//

#include "header.h"

/**
 * Given a non-empty binary tree, return the average value of the nodes on
 * each level in the form of an array.
 */

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        vector<vector<int>> layer;
        queue<pair<TreeNode *, int>> q;
        vector<pair<TreeNode *, int>> vec;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode *, int> tmp = q.front();
            q.pop();
            vec.push_back(tmp);

            if (tmp.first->left) {
                q.push(make_pair(tmp.first->left, tmp.second + 1));
            }

            if (tmp.first->right) {
                q.push(make_pair(tmp.first->right, tmp.second + 1));
            }
        }

        int max_layer = -1;
        for (auto x:vec) {
            if (x.second > max_layer) {
                max_layer = x.second;
            }
        }

        for (int i = 0; i <= max_layer; i++) {
            vector<int> tmp;
            layer.push_back(tmp);
        }


        for (auto x:vec) {
            layer[x.second].push_back(x.first->val);
        }

        for (auto outer:layer) {
            int n = int(outer.size());
            double sum = 0.0;
            for (auto inner:outer) {
                sum += inner;
            }
            res.push_back(sum / n);
        }

        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}