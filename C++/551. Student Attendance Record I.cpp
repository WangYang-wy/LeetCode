//
// Created by 王阳 on 2018/5/11.
//

#include "header.h"

class Solution {
public:
    bool checkRecord(string s) {
        int abnum = 0;
        int latenum = 0;
        int lastnum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                abnum++;
                lastnum = max(lastnum, latenum);
                latenum = 0;
            } else if (s[i] == 'L') {
                latenum++;
            } else {
                lastnum = max(lastnum, latenum);
                latenum = 0;
            }

        }

        lastnum = max(lastnum, latenum);
        if (abnum > 1 || lastnum > 2)
            return false;
        return true;

    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}