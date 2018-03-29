//
// Created by 王阳 on 2018/3/29.
//

/*
 * The set S originally contains numbers from 1 to n.
 * But unfortunately, due to the data error, one of the numbers in the set got
 * duplicated to another number in the set, which results in repetition of one
 * number and loss of another number.
 * Given an array nums representing the data status of this set after the error.
 * Your task is to firstly find the number occurs twice and then find the number
 * that is missing. Return them in the form of an array.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums_TLE(vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            std::cout << nums[i] << std::endl;
        }

        // 排序完成。

        vector<int> res;
        // 寻找重复值。
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[i + 1]) {
                res.push_back(nums[i]);
                break;
            }
        }

        // 寻找缺失的值。
        for (int value = 1; value <= nums.size(); value++) {
            if (value != nums[value] && value != nums[value - 1]) {
                res.push_back(value);
            }
        }
        return res;
    }

    /**
     * 利用符号位来查看。
     * 参考博客：https://blog.csdn.net/woshichaoren000/article/details/76147116
     * @param nums
     * @return
     */
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> ans;

        // 找到重复值。
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1; // 将数组元素值与序号同时利用。
            if (nums[index] > 0) { // 变符号，变了一次就会负数，如果再遇到，那么说明就遇到了两次。
                nums[index] *= -1;
            } else {
                ans.push_back(index + 1);
            }
        }

        // 便利一边，所有出现过（1次和2次）的，索引-1对应的元素值都是负的。

        // 寻找缺失的值。
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) { // 如果某个元素的值大于零，如果没有变化过。
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};


int main() {
    Solution *solution = new Solution();
    vector<int> s;
    s.push_back(1);
    s.push_back(3);
    s.push_back(2);
    s.push_back(-1);
    s.push_back(10);
    solution->findErrorNums(s);
//    printf("%d\n", solution)
    return 0;
}