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

    void printByBit(int num) {
        std::cout << "从最高位到最低位打印一个32位整数的各个bit位：" << std::endl;
        for (int i = 0; i < 32; i++) {
            std::cout << "第" << i + 1 << "位的值为：" << ((num & (1 << (31 - i))) >> (31 - i)) << "." << std::endl;
        }
    }

    void printByBit_(int num) {
        int n = ceil(log2(num));
        std::cout << "从最高位到最低位打印一个32位整数的各个bit位：" << std::endl;
        for (int i = 0; i < n; i++) {
            int bit = ((num & (1 << (n - i - 1))) >> (n - i - 1));
            std::cout << "第" << i + 1 << "位的值为：" << bit << "." << std::endl;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->findComplement(5) << std::endl;
//    solution->printByBit_(5);
//    std::cout << ((1 << 31)) << std::endl;
    return 0;
}