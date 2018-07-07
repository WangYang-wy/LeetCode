//
// Created by 王阳 on 2018/3/28.
//

/*
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest sum.
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

/**
 * 参考博客：https://www.cnblogs.com/mengfanrong/p/5282042.html
 */
#include "header.h"

class Solution {
public:
    // 程序的时间复杂度不对。O(n^3)，附加空间复杂度O(1)。
    int maxSubArray_TLE(vector<int> &nums) {
        int n = nums.size();
        int ans = -2147483648;  // INT 最小的数据。
        for (int st = 0; st < n; ++st) {
            for (int ed = st + 1; ed <= n; ++ed) {
                int sum = 0;
                for (int i = st; i < ed; ++i) {
                    sum += nums[i];  // 优化先找最内层的循环，执行次数最多，累计求和，是优化的方向。
                }
                if (sum > ans) {
                    ans = sum;
                }
            }
        }
        return ans;
    }

    // 去掉了 sum 的冗余，每一个数字会被加入到 sum
    int maxSubArray_TLE_opt(vector<int> &nums) {
        int n = nums.size();
        int ans = -2147483648;  // INT 最小的数据。
        for (int st = 0; st < n; ++st) {
            int sum = 0;
            for (int ed = st + 1; ed <= n; ++ed) {
                sum += nums[ed - 1];
                if (sum > ans) {
                    ans = sum;
                }
            }
        }
        return ans;
    }

    // 求和变成求差，求最大变成最小。
    int maxSubArray(vector<int> &nums) {
        int ans = INT_MIN;  //设置最小值
        int n = nums.size();
        int sj = 0;
        int minSi = 0;
        int si = 0;
        int sum = si - minSi;
        for (int j = 0; j < n; ++j) {
            sj += nums[j];
            if (si < minSi) {
                minSi = si;
            }

            if (sj - minSi > ans) {
                ans = sj - minSi;
            }
            si += nums[j];
        }
        return ans;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(1);
    printf("%d\n", solution->maxSubArray(a));
    return 0;
}
