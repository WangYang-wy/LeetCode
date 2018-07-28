//
// Created by 王阳 on 2018/7/28.
//

#include "header.h"

class Solution {
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        int left = 0;
        int up = 1;
        int right = 2;
        int down = 3;

        // 1 在 2 的上面。
        if (rec1[down] > rec2[up]) {
            return false;
        }

        // 1 在 2 的下面。
        if (rec1[up] < rec2[down]) {
            return false;
        }

        // 1 在 2 的左边。
        if (rec1[right] < rec2[left]) {
            return false;
        }

        // 1 在 2 的右边。
        if (rec1[left] > rec2[right]) {
            return false;
        }

        return true;
    }
};

int main() {
    return 0;
}
