//
// Created by 王阳 on 2018/8/21.
//

#include "header.h"

class Solution {
public:
    int numTrees(int n) {
        int *G = new int[n + 1]();
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++)
                G[i] += G[j] * G[i - j - 1];
        }
        return G[n];
    }
};


int main() {
    return 0;
}