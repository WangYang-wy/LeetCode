//
// Created by 王阳 on 2018/7/27.
//

#include "header.h"

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        int n = int(A.size());
        int count = 0;
        vector<int> my_set;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                my_set.push_back(A[i] + B[j]);
            }
        }

        sort(my_set.begin(), my_set.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmp = C[i] + D[j];
                count += (upper_bound(my_set.begin(), my_set.end(), -tmp)
                          - lower_bound(my_set.begin(), my_set.end(), -tmp));
            }
        }
        return count;
    }
};

int main() {
    return 0;
}
