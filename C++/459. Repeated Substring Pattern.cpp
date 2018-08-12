//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int m = int(str.length());
        for (int p = 1; p < m / 2 + 1; p++)
            for (int i = 0; i < m - p; i++) {
                if (str[i] != str[i + p]) {
                    break;
                }
                if (0 == m % p && i == m - p - 1) {
                    return true;
                }
            }
        return false;
    }
};

int main() {
    return 0;
}