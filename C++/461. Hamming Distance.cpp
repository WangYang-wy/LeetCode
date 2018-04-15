//
// Created by 王阳 on 2018/4/15.
//

#include "header.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if ((x & (1 << 1)) != (y & (1 << 1))) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}