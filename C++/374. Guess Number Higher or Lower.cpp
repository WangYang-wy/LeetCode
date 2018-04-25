//
// Created by 王阳 on 2018/4/25.
//

#include "header.h"

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        int min;
        int res;
        while (low < high) {
            mid = low + (high - low) / 2;
            res = guess(mid);
            if (-1 == res) {
                high = mid - 1;
            } else if (1 == res) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return low;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}