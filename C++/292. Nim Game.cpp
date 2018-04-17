//
// Created by 王阳 on 2018/4/17.
//

#include "header.h"

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}