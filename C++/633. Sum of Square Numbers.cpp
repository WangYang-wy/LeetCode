//
// Created by 王阳 on 2018/5/14.
//

#include "header.h"

class Solution {
public:
    // 双指针问题。
    bool judgeSquareSum(int c) {
        int i = 0;
        int j = int(sqrt(c));
        while (i <= j) {
            int num = i * i + j * j;
            if (c == num) {
                return true;
            } else if (num < c) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}