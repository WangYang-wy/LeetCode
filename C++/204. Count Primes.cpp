//
// Created by 王阳 on 2018/3/27.
//

/*
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 */

/**
 * 质数定义为在大于1的自然数中，除了1和它本身以外不再有其他因数。
 */
#include <math.h>
#include <iostream>

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) {
                printf("i = %d\n", i);
                count++;
            }
        }
        return count;
    }

    /**
     * 判断是否为素数。
     * @param n 数字。
     * @return 是否为素数。
     */
    bool isPrime(int n) {
        int n_ = int(sqrt(n));
        for (int i = 2; i <= n_; i++) {
            if (0 == n % i) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%d\n", solution->countPrimes(5));
    return 0;
}