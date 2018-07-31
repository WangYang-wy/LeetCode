//
// Created by 王阳 on 2018/7/31.
//

#include "header.h"

class Solution {
private:
    int binary_to_gray(int n) {
        return n ^ (n >> 1);
    }

public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.clear();
        int size = 1 << n;
        res.reserve(size);
        for (int i = 0; i < size; ++i) {
            res.push_back(this->binary_to_gray(i));
        }
        return res;
    }
};

int main() {
    return 0;
}
