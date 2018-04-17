//
// Created by 王阳 on 2018/4/17.
//

#include "header.h"

/**
 * 参考博客：https://blog.csdn.net/fly_yr/article/details/50173755
 * 给定一个整数序列，求指定子序列和。
 * 提示：数组不会发生变化；大量sumRange函数调用。
 * 题目本身非常简单，只需要遍历 i 到 j ，累计得到和即可。但是，这样是TLE的，所给提示也就没有意义了。
 * 所以，题目考察的是效能，换一个方向思考，我们可以存储子序列和，每个下标处的值为[0,i]的所有元素和;
 * 那么[i,j]子序列和 =sum[j]−sum[i−1]；
 * 注意，i==0时，直接返回sum[j]即可。
 */

class NumArray {
private:
    vector<int> my_nums;
public:
    NumArray(vector<int> nums) {
        if (nums.empty()) {
            return;
        } else {
            this->my_nums.push_back(nums[0]);
            int n = int(nums.size());
            for (int i = 1; i < n; i++) {
                this->my_nums.push_back(this->my_nums[i - 1] + nums[i]);
            }
        }
    }

    int sumRange(int i, int j) {
        if (0 == i) {
            return this->my_nums[j];
        }

        int n = this->my_nums.size();
        if (i < 0 || i >= n || j < 0 || j >= n || i > j) {
            return 0;
        }
        return this->my_nums[j] - this->my_nums[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main() {
    Solution *solution = new Solution();
    return 0;
}