//
// Created by 王阳 on 2018/3/30.
//

#include "header.h"

/**
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 x is guaranteed to be a non-negative integer.
 */
class Solution {
public:
    int mySqrt(int x) {
        return int(sqrt(x));
    }

    // 第二种解法：二分的方式。
    bool guess(int x, int y) {
        return x * x <= y;
    }

    int mySqrt(int x) {
        int left = 0;
        int right = x; // 二分的区间，左闭右开。
        int ans = 0;
        while (left < right) {
            int mid = left + (right - left) / 2; // 防止溢出。
            if (this->guess(mid, x)) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%d\n", solution->mySqrt(2147483647));
    return 0;
}