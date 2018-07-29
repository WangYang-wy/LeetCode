//
// Created by 王阳 on 2018/7/29.
//

#include "header.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool res = false;
        int n_1 = int(s1.size());
        int n_2 = int(s2.size());
        sort(s2.begin(), s2.end());
        for (int i = 0; i <= n_1 - n_2; ++i) {
            string tmp = s1.substr(i, n_2);
            sort(tmp.begin(), tmp.end());
            if (tmp == s2) {
                res = true;
                break;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
