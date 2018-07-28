//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

// Definition for an interval.
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    /**
     * 是否有重叠。
     * @param a Interval a.
     * @param b Interval b.
     * @return 是否重叠。
     */
    bool isOverlap(Interval &a, Interval &b) {
        Interval tmp;
        if (a.start >= b.start && a.end <= b.end) { // a 在里面。
            tmp = Interval(b.start, b.end);
            this->res.push_back(tmp);
            return true;
        } else if (a.start <= b.start && a.end >= b.end) { // b 在里面。
            tmp = Interval(a.start, a.end);
            this->res.push_back(tmp);
            return true;
        } else if (a.start <= b.start && a.end <= b.end && b.start <= a.end) { // a 在左。
            tmp = Interval(a.start, b.end);
            this->res.push_back(tmp);
            return true;
        } else if (b.start <= a.start && b.end <= a.end && a.start <= b.end) { // a 在右。
            tmp = Interval(b.start, a.end);
            this->res.push_back(tmp);
            return true;
        } else {
            return false;
        }
    }

    bool hasOverlap() {
        int n = int(this->res.size());
        bool flag = false;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (this->isOverlap(this->res[i], this->res[j])) {
                    this->res.erase(this->res.begin() + j);
                    this->res.erase(this->res.begin() + i);
                    return true;
                }
            }
        }
        return flag;
    }

    vector<Interval> res;

public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = int(intervals.size());
        res.clear();
        for (int i = 0; i < n; ++i) {
            this->res.push_back(intervals[i]);
        }

        while (this->hasOverlap()) { ;
        }
        return this->res;
    }
};

int main() {
    return 0;
}
