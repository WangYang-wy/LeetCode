//
// Created by 王阳 on 2018/4/18.
//

#include "header.h"

class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int n = ceil(log2(num));
        for (int i = 0; i < n; i++) {
            int index = 1 - ((num & (1 << (n - i - 1))) >> (n - i - 1));
            res = (res << 1) + index;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->findComplement(5) << std::endl;
    return 0;
}