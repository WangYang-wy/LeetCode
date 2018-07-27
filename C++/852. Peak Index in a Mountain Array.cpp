//
// Created by 王阳 on 2018/7/27.
//
#include "header.h"

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &A) {
        int n = int(A.size());
        int index = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
                index = i;
                break;
            }
        }
        return index;
    }
};

int main() {
    return 0;
}
