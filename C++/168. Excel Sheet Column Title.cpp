//
// Created by 王阳 on 2018/4/13.
//

#include "header.h"

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            res = (char) ((n - 1) % 26 + 'A') + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->convertToTitle(26) << std::endl;
    std::cout << solution->convertToTitle(27) << std::endl;
    std::cout << solution->convertToTitle(1) << std::endl;
    return 0;
}