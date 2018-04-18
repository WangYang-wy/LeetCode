//
// Created by 王阳 on 2018/4/18.
//

#include "header.h"

class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }
        int x = a ^b;
        int c = (a & b) << 1;
        return getSum(c, x);
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}