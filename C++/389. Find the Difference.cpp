//
// Created by 王阳 on 2018/5/2.
//

#include "header.h"

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int n = int(s.length());
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                return t[i];
            }
        }
        return t[n];
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}