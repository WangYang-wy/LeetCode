//
// Created by 王阳 on 2018/10/14.
//

#include "header.h"

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = int(word.length());
        if (0 == n || 1 == n) {
            return true;
        }

        if ('a' <= word[0] && word[0] <= 'z') { // 第一个是小写数字。
            for (int i = 1; i < n; ++i) {
                if ('a' <= word[i] && word[i] <= 'z') { // 全是小写。
                    ;
                } else {
                    return false;
                }
            }
            return true;
        } else { // 第一个是大写。
            if ('a' <= word[1] && word[1] <= 'z') { // 第二个是小写，则必须全是小写。
                for (int i = 2; i < n; ++i) {
                    if ('a' <= word[i] && word[i] <= 'z') { // 全是小写。
                        ;
                    } else {
                        return false;
                    }
                }
                return true;
            } else { // 第二个是大写，则必须全是大写。
                for (int i = 2; i < n; ++i) {
                    if ('A' <= word[i] && word[i] <= 'Z') { // 全是小写。
                        ;
                    } else {
                        return false;
                    }
                }
                return true;
            }
        }
    }
};

int main() {
    return 0;
}