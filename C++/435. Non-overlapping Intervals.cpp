//
// Created by 王阳 on 2018/5/14.
//

#include "header.h"

/**
 * 直接计算最多能组成的不重叠区间个数即可。
 */

/**
 * 按区间的结尾进行排序，每次选择结尾最小，并且和前一个区间不重叠的区间。
 */

/**
 * 参考博客：https://blog.csdn.net/lby0910/article/details/70145137
 */

class Solution {
public:
    // 按照end进行升序排列。
    static bool Compare(Interval a, Interval b) {
        if (a.end <= b.end) {
            if (a.end < b.end) {
                return true;
            }
            return a.start <= b.start;
        }
        return false;
    }

    int eraseOverlapIntervals(vector<Interval> &intervals) {
        int n = int(intervals.size());
        if (0 == n) {
            return 0;
        }

        int counter = 0;
        sort(intervals.begin(), intervals.end(), Compare);

        int reference = intervals[0].end;
        for (int i = 1; i < int(intervals.size()); i++) {
            if (intervals[i].start < reference) {
                counter++;
            } else {
                reference = intervals[i].end;
            }
        }
        return counter;
    }
};


int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}