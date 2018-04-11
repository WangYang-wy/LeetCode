//
// Created by 王阳 on 2018/4/11.
//

#include "header.h"

/**
 * 使用递归会导致超时，所以使用循环代替。
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int a = 0;
        int b = 1;
        int c = 2;
        int res = 0;

        for (int i = 3; i <= n; i++) {
            res = b + c;
            b = c;
            c = res;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->climbStairs(1) << std::endl;
    std::cout << solution->climbStairs(2) << std::endl;
    std::cout << solution->climbStairs(3) << std::endl;
    std::cout << solution->climbStairs(4) << std::endl;
    std::cout << solution->climbStairs(5) << std::endl;
    return 0;
}