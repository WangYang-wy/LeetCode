//
// Created by 王阳 on 2018/10/14.
//

#include "header.h"

class Solution {
private:
    int C(int m, int n) {
        int res = 1;
        for (int i = 0; i < n; ++i) {
            res *= (m - i);
        }

        for (int i = 0; i < n; ++i) {
            res /= (1 + i);
        }
        return res;
    }

public:
    int countNumbersWithUniqueDigits(int n) {

    }
};

int main() {
    return 0;
}