//
// Created by 王阳 on 2018/7/28.
//

#include "header.h"

class Solution {
public:
    string reverseWords(string s) {
        int n = int(s.length());
        if (0 == n) {
            return 0;
        }
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (' ' == s[i]) {
                reverse(s.begin() + index, s.begin() + i);
                index = i + 1;
            }
        }
        reverse(s.begin() + index, s.end());
        return s;
    }
};

int main() {
    return 0;
}
