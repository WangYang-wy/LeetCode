//
// Created by 王阳 on 2018/4/10.
//
/**
 * Given a non-negative integer num,
 * repeatedly add all its digits until the result has only one digit.
 * For example:
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2.
 * Since 2 has only one digit, return it.
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating
 * all test cases.
 */
#include "header.h"

/**
 * 参考博客：https://blog.csdn.net/will130/article/details/51187597
 */

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%d.\n", solution->addDigits(38));
    return 0;
}