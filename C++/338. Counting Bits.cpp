//
// Created by 王阳 on 2018/10/14.
//

#include "header.h"

class Solution {
private:
    vector<int> res;
public:
    vector<int> countBits(int num) {
        this->res.clear();
        for (int i = 0; i <= num; ++i) {
            this->res.push_back(0);
        }

        for (int i = 1; i <= num; ++i) {
            this->res[i] = this->res[i / 2] + i % 2;
        }

        return this->res;
    }
};
