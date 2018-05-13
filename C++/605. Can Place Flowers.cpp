//
// Created by 王阳 on 2018/5/13.
//

#include "header.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int len = int(flowerbed.size());
        int count = 0; // 可以种下的个数。

        for (int i = 0; i < len; i++) {
            if (1 == flowerbed[i]) {
                continue;
            }

            // 在这里，想到与在一头一尾都补了一个0。
            int pre = (i == 0 ? 0 : flowerbed[i - 1]); // 前面一个。
            int next = (i == len - 1 ? 0 : flowerbed[i + 1]); // 后面一个。

            if (pre == 0 && next == 0) {
                count++;
                flowerbed[i] = 1;
            }
        }
        return count >= n;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}