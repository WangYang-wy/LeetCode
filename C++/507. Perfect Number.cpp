//
// Created by 王阳 on 2018/5/2.
//

#include "header.h"

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int sum = 0;
        for (int i = 2; i < sqrt(num); i++)
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        sum++;
        return sum == num;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}