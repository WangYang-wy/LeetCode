//
// Created by 王阳 on 2018/7/26.
//

#include "header.h"

class Solution {
public:
    bool is_valid(int X) {
        int tmp = X;
        int reverse = 0;
        int k = 1;
        while (X > 0) {
            int bit = X % 10; // 先获取各位。
            if (0 == bit) {
                reverse = reverse + 0 * k;
            } else if (1 == bit) {
                reverse = reverse + 1 * k;
            } else if (8 == bit) {
                reverse = reverse + 8 * k;
            } else if (6 == bit) {
                reverse = reverse + 9 * k;
            } else if (9 == bit) {
                reverse = reverse + 6 * k;
            } else if (2 == bit) {
                reverse = reverse + 5 * k;
            } else if (5 == bit) {
                reverse = reverse + 2 * k;
            } else {
                return false;
            }
            X /= 10;
            k *= 10;
        }
        return reverse != tmp;
    }

    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (this->is_valid(i)) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->rotatedDigits(10) << std::endl;
    delete solution;
    return 0;
}
