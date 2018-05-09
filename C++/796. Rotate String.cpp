//
// Created by 王阳 on 2018/5/9.
//

#include "header.h"

class Solution {
public:
    bool rotateString(string A, string B) {
        int n_a = int(A.size());
        int n_b = int(B.size());
        if (n_a != n_b) {
            return false;
        } else {
            int n = n_a;
            for (int i = 1; i < n - 1; i++) {
                string sub_1 = A.substr(0, i);
                string sub_2 = A.substr(i);
                if (sub_2 + sub_1 == B) {
                    return true;
                }
            }
            return false;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}