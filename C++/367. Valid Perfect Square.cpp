//
// Created by 王阳 on 2018/3/29.
//

/*
 * Given a positive integer num, write a function which returns True if num
 * is a perfect square else False.
 */

/**
 * 参考博客：https://www.cnblogs.com/grandyang/p/5619296.html
 * 这道题给了我们一个数，让我们判断其是否为完全平方数，那么显而易见的是，肯定不能使用brute force，
 * 这样太不高效了，那么最小是能以指数的速度来缩小范围，那么我最先想出的方法是这样的，比如一个数字49，
 * 我们先对其除以2，得到24，发现24的平方大于49，那么再对24除以2，得到12，发现12的平方还是大于49，
 * 再对12除以2，得到6，发现6的平方小于49，于是遍历6到12中的所有数，看有没有平方等于49的，有就返回true，
 * 没有就返回false。
 *
 * 另一个解法：我们也可以使用二分查找法来做，要查找的数为mid*mid。
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare_time(int num) { // 二分查找的思想。
        int left = 0, right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2, t = mid * mid;
            if (t == num) {
                return true;
            } else if (t < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    /**
     * 1 = 1
     * 4 = 1 + 3
     * 9 = 1 + 3 + 5
     * 16 = 1 + 3 + 5 + 7
     * 25 = 1 + 3 + 5 + 7 + 9
     * 36 = 1 + 3 + 5 + 7 + 9 + 11
     * ....
     * 1+3+...+(2n-1) = (2n-1 + 1)n/2 = n*n
     * 直接用公式。
     * @param num 一个数。
     * @return 判断是否为完全平方数，效率为O(sqrt(n)).
     */
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};


int main() {
    Solution *solution = new Solution();
    printf("%d\n", solution->isPerfectSquare(2147483647));
    return 0;
}