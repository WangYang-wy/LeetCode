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
#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max = INT_MIN;//设置最小值
        int sum = 0;//每一个分组的和
        int i = 0;
        while (i < nums.size()) {
            sum += nums[i];//每一个分组的前n项和
            if (max < sum) {
                max = sum;//取最大和
            }
            if (sum < 0) {//假设<0。分组结束，開始下一组
                sum = 0;
            }
            i++;
        }
        return max;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a;
    a.push_back(1);
    printf("%d\n", solution->maxSubArray(a));
    return 0;
}