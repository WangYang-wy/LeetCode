//
// Created by 王阳 on 2018/5/14.
//

#include "header.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int n_s = int(s.size());
        int n_t = int(t.size());
        int index = -1;
        for (int i = 0; i < n_s; i++) {
            char search = s[i];
            bool flag = false;
            for (int j = index + 1; j < n_t; j++) {
                if (search == t[j]) { // 如果相等。
                    flag = true;
                    index = j;
                    break;
                }
            }

            if (!flag) { // 没找到。
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}