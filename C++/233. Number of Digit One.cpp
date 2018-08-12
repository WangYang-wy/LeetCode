//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"

class Solution {
public:
    /**
     * 参考博客：https://blog.csdn.net/xudli/article/details/46798619
     * @param n 整数。
     * @return 解答。
     */
    int countDigitOne(int n) {
        int count = 0;
        for (int i = 1; i <= n; i *= 10) {
            int a = n / i;
            int b = n % i;
            count += (a + 8) / 10 * i;
            if (1 == a % 10) {
                count += b + 1;
            }
        }
        return count;
    }
};

int main() {
    return 0;
}