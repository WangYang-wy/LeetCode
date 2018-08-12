//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node *root) {
        if (nullptr == root) {
            return 0;
        }

        if (0 != int(root->children.size())) {
            return 1;
        }
        vector<int> children_depth;
        for (auto x:root->children) {
            children_depth.push_back(this->maxDepth(x));
        }

        int max_value = -1;
        for (auto x:children_depth) {
            if (x > max_value) {
                max_value = x;
            }
        }
        return 1 + max_value;
    }
};

int main() {
    return 0;
}