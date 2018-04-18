//
// Created by 王阳 on 2018/4/18.
//

#include "header.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m != n) // 长度不等。
            return false;
        unordered_map<char, char> m1;   //s --> t
        unordered_map<char, char> m2;   //t --> s
        for (int i = 0; i < m; i++) {
            char schar = s[i];
            char tchar = t[i];
            // the same char in s map to different chars in t
            if (m1.find(schar) != m1.end() && m1[schar] != tchar)
                return false;
            // two different chars in s map tp the same char in t
            if (m2.find(tchar) != m2.end() && m2[tchar] != schar)
                return false;
            m1[schar] = tchar;
            m2[tchar] = schar;
        }
        return true;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->isIsomorphic("egg", "add") << std::endl;
    return 0;
}