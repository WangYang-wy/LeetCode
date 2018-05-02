//
// Created by 王阳 on 2018/5/2.
//

#include "header.h"

/**
 * 参考博客：https://segmentfault.com/a/1190000007275810
 * 先建立hash表，然后两层遍历，查找第三个余数是否存在。余数直接用sum减去前两个的和。
 * 先做好排序，nlogn比n^2小很多，多做一次不影响。
 * 遍历时，如果发现要求的第三个数已经比第二个数小，就可以跳过后续了，因为不可能找到了。
 * 即由于有序，这三个数是在排序后的数组有序且递增的。
 * 如果第一个数就大于0，则整体肯定大于0，可以全部跳过后续。
 * 考虑做去重，由于有序，在同一个第一个数下，当前的第二个数如果等于上一次的第二个数，则整体一定相同，可以跳过。
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int> > ret;
        if (nums.size() == 0) {
            return ret;
        }
        sort(nums.begin(), nums.end()); // 先排序。
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) {
                return ret;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (j - 1 > i && nums[j] == nums[j - 1]) {
                    continue;
                }
                int two = nums[i] + nums[j];
                if (-two < nums[j]) {
                    break;
                }
                if (two > 0) {
                    return ret;
                }
                auto it = map.find(-two);
                if (it != map.end() && it->second > j) {
                    vector<int> r;
                    r.push_back(nums[i]);
                    r.push_back(nums[j]);
                    r.push_back(-two);
                    ret.push_back(r);
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}