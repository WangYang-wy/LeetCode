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
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int ans = INT_MIN;  // INT 最小的数据。
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

    // 去掉了 sum 的冗余，每一个数字会被加入到 sum，累计 st 到 ed。
    int maxSubArray_better(vector<int> &nums) {
        int n = nums.size();
        int ans = INT_MIN;  // INT 最小的数据。

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
    int maxSubArray_best(vector<int> &nums) {
        int ans = INT_MIN;  // 设置最小值。
        int n = nums.size();

        int s = new int[n + 1]; // 求和数组，存储部分和。
        s[0] = 0; // 表示没有数字。
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + nums[i]; // s[i] 表示前 i 个数字的和。
        }

        for (int j = 0; j < n; j++) { // 固定 j，寻找最小的 i。
            int min = 0;
            for (int i = 0; i < j; i++) { // 每次 j 增加，i 又从 0 开始遍历，这里有冗余。
                if (s[i] < min) {
                    min = s[i];
                }
            }
            if (s[j] - min > ans) {
                ans = s[j] - min;
            }
        }

        return ans;
    }

    // 化简写法。
    int maxSubArray_best_opt(vector<int> &nums) {
        int ans = INT_MIN;  // 设置最小值。
        int n = nums.size();
        int sj = 0;
        int si = 0;
        int minSi = 0;
        // min[0, 6] = min(min[0, 5], min[6, 6])
        // 求和变求差，求积变求和。
        // 在一次遍历中，j 比 i 跑得快，由于 i 跑得慢，需要需要记录最小的前 i 项和，
        // 同时每次遍历的时候，记录最大的前 j 项和。
        for (int j = 0; j < n; j++) {
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

    int maxSubArray_best_opt_opt(vector<int> &nums) {
        int ans = INT_MIN;  // 设置最小值。
        int n = nums.size();

        int sum = 0; // 数组的前 j 项和。

        for (int j = 0; j < n; j++) {
            sum += nums[j]; // 累计前 j 项和。

            if (sum > ans) { // 如果求和大于了设定值，那么更新。
                ans = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
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
