//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
private:
    int left_used = 0;
    int right_used = 0;
    int length;
    vector<string> res;
    vector<char> path;

    void fun(int idx, int left, int right) {
        if (0 == left && 0 == right) {
            string tmp;
            for (auto x:this->path) {
                tmp += x;
            }
            this->res.push_back(tmp);
            std::cout << tmp << std::endl;
            return;
        }

        if (0 == left) { // 如果左括号用完了，只能使用右括号。
            this->path[idx] = ')';
            this->right_used++;
            this->fun(idx + 1, left, right - 1);
            this->right_used--;
        } else if (this->left_used == this->right_used) { // 如果左右括号使用次数相同，那么必须先使用左括号。
            this->path[idx] = '(';
            this->left_used++;
            this->fun(idx + 1, left - 1, right);
            this->left_used--;
        } else { // 否则，左右都可以使用。
            this->path[idx] = '(';
            this->left_used++;
            this->fun(idx + 1, left - 1, right);
            this->left_used--;

            this->path[idx] = ')';
            this->right_used++;
            this->fun(idx + 1, left, right - 1);
            this->right_used--;
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        this->res.clear();
        this->path.clear();
        int left = n;
        int right = n;
        this->length = 2 * n;
        for (int i = 0; i < this->length; ++i) {
            this->path.push_back(0);
        }
        this->path[0] = '(';
        this->path[this->length - 1] = ')';
        this->left_used++;
        this->fun(1, left - 1, right - 1);
        return this->res;
    }
};

int main() {
    Solution *solution = new Solution();
    solution->generateParenthesis(3);
    delete solution;
    return 0;
}
