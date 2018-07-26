//
// Created by 王阳 on 2018/7/26.
//

#include "header.h"

class Solution {
public:
    bool guess(int g, vector<vector<int>> &matrix, int k) {
        int n = int(matrix.size());
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = n - 1; // [L, R].
            int ans = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] < g) {
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            sum += (ans + 1);
        }
        return k > sum;
    }

    // k 越大，返回值越大。有一个单调性。
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int ans;
        int n = int(matrix.size());
        int right = matrix[n - 1][n - 1];
        int left = matrix[0][0];

        // [L, R]
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (this->guess(mid, matrix, k)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
