//
// Created by 王阳 on 2018/7/29.
//

#include "header.h"


class Solution {
public:
    bool validPalindrome(string s) {
        int i, j;
        int si, sj; // 用于回溯。
        int n = s.size();
        int count = 0;
        int way = 0;

        for (i = 0, j = n - 1; i < j; i++, j--) {
            if (s[i] == s[j]) { // 如果相等。
                continue;
            } else {
                if (way == 2) {
                    return false;
                } else if (way == 1) {
                    way++;
                    i = si;
                    j = sj;
                    j++;
                } else if (way == 0) {
                    way++;
                    count = 1;
                    si = i;
                    sj = j;
                    i--;
                }
            }
        }
        return true;
    }


    int main() {
        return 0;
    }
