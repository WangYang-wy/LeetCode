//
// Created by 王阳 on 2018/7/31.
//

#include "header.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        // 每次循环删除第一个下降的元素。
        string tmp = num;
        if (k >= num.length()) {
            return string("0");
        }
        for (int i = 0; i < k; ++i) {
            int max_index = -1;
            for (int j = 0; j < int(tmp.length()) - 1; ++j) {
                if (tmp[j] > tmp[j + 1]) {
                    max_index = j;
                    break;
                }
            }
            if (-1 == max_index) {
                tmp.erase(tmp.length() - 1, 1);
            } else {
                tmp.erase(max_index, 1);
            }
        }
        while ('0' == tmp[0]) {
            tmp.erase(0, 1);
        }
        if (tmp == "") {
            return "0";
        }
        return tmp;
    }
};

int main() {
    return 0;
}
