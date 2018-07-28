//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
public:
    void reverseWords(string &s) {
        while (' ' == s[0]) {
            s.erase(0, 1);
        }
        while (' ' == s[int(s.length()) - 1]) {
            s.erase(s.length() - 1, 1);
        }

        int n = int(s.length());
        for (int i = n - 1; i > 1; --i) {
            if (' ' == s[i] && s[i - 1] == s[i]) {
                s.erase(i, 1);
            }
        }

        n = int(s.length());
        int index = 0;
        int last = 0;

        for (int i = 1; i < n; i++) {
            if (' ' == s[i]) {
                reverse(s.begin() + index, s.begin() + i);
                index = i + 1;
                last = i + 1;
            }
        }
        reverse(s.begin() + last, s.end());
        reverse(s.begin(), s.end());
    }
};

int main() {
    Solution *solution = new Solution();
    string a = "the sky is blue";
    solution->reverseWords(a);
    std::cout << a << std::endl;
    delete solution;
    return 0;
}
