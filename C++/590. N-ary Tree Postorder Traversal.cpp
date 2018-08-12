//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"

//   Definition for a Node.
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
private:
    vector<int> res;
public:
    vector<int> postorder(Node *root) {
        if (nullptr == root) {
            return this->res;
        }

        for (auto x:root->children) {
            this->postorder(x);
        }
        this->res.push_back(root->val);
        return this->res;
    }
};

int main() {
    return 0;
}