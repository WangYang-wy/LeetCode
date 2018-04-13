//
// Created by 王阳 on 2018/4/13.
//

#include "header.h"

class Solution {
public:
    double myPow_tle(double x, int n) {
        double res = 1;
        if (0 == n) {
            return 1;
        } else if (n > 0) {
            while (n > 0) {
                res = res * x;
                n--;
            }
        } else {
            while (n < 0) {
                res = res / x;
                n++;
            }
        }
        return res;
    }

    /**
     * 采用了分治的思想，将线性时间，降为对数时间。
     * 参考博客：https://blog.csdn.net/u010002184/article/details/77073171
     * @param x 数。
     * @param n 次方。
     * @return pow.
     */
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        double temp = myPow(x, n / 2);
        if (0 == n % 2) {
            return temp * temp;
        } else {
            if (n > 0) {
                return x * temp * temp;
            } else {
                return temp * temp / x;
            };
        }
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->myPow(2.1, 3) << std::endl;
    std::cout << solution->myPow(2, -1) << std::endl;
    return 0;
}

