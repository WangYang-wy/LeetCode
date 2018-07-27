//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
public:
    string toLowerCase(string str) {
        string res;
        int n = int(str.length());
        for (int i = 0; i < n; ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                res += str[i] - ('A' - 'a');
            } else  {
                res += str[i];
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
