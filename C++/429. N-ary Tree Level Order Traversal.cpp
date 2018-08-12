//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"


// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        if (nullptr == root) {
            return res;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int n = int(q.size());
            vector<int> vec;
            vec.clear();
            for (int i = 0; i < n; ++i) {
                Node *tmp = q.front();
                vec.push_back(tmp->val);

                for (auto x:tmp->children) {
                    q.push(x);
                }
                q.pop();
            }
            res.push_back(vec);
        }
        return res;
    }
};

int main() {
    return 0;
}