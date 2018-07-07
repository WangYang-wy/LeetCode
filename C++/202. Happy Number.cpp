//
// Created by 王阳 on 2018/3/27.
//

/*
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process:
 * Starting with any positive integer, replace the number
 * by the sum of the squares of its digits,
 * and repeat the process until the number equals 1 (where it will stay),
 * or it loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy numbers.
 */


/**
 * 判断每个数的各个位数平方和计算完毕后所得结果有无出现过，若从未出现，则继续计算，
 * 否则判断此数不是happy number。
 * 那么一定是在相加的过程中出现了数的循环，1不含在循环中。
 * 参考博客：https://www.cnblogs.com/VickyWang/p/6025253.html
 */
#include "header.h"

class Solution {
public:
    bool isHappy(int n) {
        map<int, int> *m = new map<int, int>();
        int result = getSquareSum(getDigits(n));
        int initial = result;
        while (true) {
            result = getSquareSum(getDigits(result));
            if ((*m)[result]++ > 0) {
                break;
            }
        }
        return result == 1;
    }

    /**
     * 给一个数，给出每一位的数字，组成一个数组。
     * @param n 数字。
     * @return 数组。
     */
    vector<int> getDigits(int n) {
        vector<int> *res = new vector<int>();
        while (n != 0) {
            res->push_back(n % 10);
            n = n / 10;
        }
        return *res;
    }

    /**
     * 接受一个数组，返回每个元素的平方和。
     * @param arr 数组。
     * @return 平方和。
     */
    int getSquareSum(vector<int> arr) {
        int result = 0;
        for (int i = 0; i < arr.size(); i++) {
            result = result + arr[i] * arr[i];
        }
        return result;
    }
};

int main() {
    Solution *solution = new Solution();
//    printf("%d\n", solution->getSquareSum(solution->getDigits(101)));
    printf("%d\n", solution->isHappy(199));
    return 0;
}