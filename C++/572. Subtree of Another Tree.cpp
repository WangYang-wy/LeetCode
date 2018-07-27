//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
private:
    vector<TreeNode *> v;

    bool isSameTree(TreeNode *s, TreeNode *t) {
        if (nullptr == s && nullptr == t) {
            return true;
        } else if (nullptr != s && nullptr != t) {
            return s->val == t->val
                   && this->isSameTree(s->left, t->left)
                   && this->isSameTree(s->right, t->right);
        } else {
            return false;
        }
    }

    void order(TreeNode *s) {
        if (nullptr == s) {
            return;
        }
        this->order(s->left);
        this->v.push_back(s);
        this->order(s->right);
    }

public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        this->order(s);
        int n = int(this->v.size());
        for (int i = 0; i < n; i++) {
            if (this->isSameTree(v[i], t)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}


