//
// Created by 王阳 on 2018/3/27.
//

/*
 * Given an integer, write a function to determine if it is a power of three.
 * Follow up:
 *  Could you do it without using any loop / recursion?
 * Credits:
 *  Special thanks to @dietpepsi for adding this problem and creating all test cases.
 */

/**
 * 参考：http://www.bubuko.com/infodetail-1320710.html
 */
#include <math.h>

class Solution {
public:
    /**
     * 使用循环。
     * @param n 整数。
     * @return 是否为3的幂。
     */
    bool isPowerOfThree_loop(int n) {
        while (n % 3 == 0) {
            n = n / 3;
        }

        if (1 == n) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * 由于输入是int，正数范围是0-231，在此范围中允许的最大的3的次方数为3^19=1162261467，
     * 那么我们只要看这个数能否被n整除即可。
     * @param n 整数。
     * @return 是否为3的幂。
     */
    bool isPowerOfThree_int(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }

    /**
     * 换底公式，因为是整数，使用a - int(a) == 0来判断。
     * @param n 整数。
     * @return 是否为3的幂。
     */
    bool isPowerOfThree(int n) {
        return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
    }
};