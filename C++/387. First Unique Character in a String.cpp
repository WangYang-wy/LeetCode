//
// Created by 王阳 on 2018/5/2.
//

#include "header.h"

class Solution {
public:
    int firstUniqChar(string s) {
        //题目要找第一个没有重复的字符，那么首先扫描一遍string存放每个字符出现的次数，
        // 再对string扫描一遍，如果次数为1那么就返回其index。
        int n = s.length();
        if (n <= 0) {
            return -1;
        }
        if (n == 1) {
            return 0;
        }
        int sta[26];
        memset(sta, 0, sizeof(sta));
        for (int i = 0; i < n; i++)
            sta[s[i] - 'a']++;
        for (int i = 0; i < n; i++) {
            if (sta[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}