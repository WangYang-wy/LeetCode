//
// Created by 王阳 on 2018/7/28.
//

#include "header.h"

class Solution {
private:
    bool binarySearch(int target, vector<int> &array) {
        int n = int(array.size());
        int left = 0;
        int right = n; // [L, R)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target == array[mid]) {
                return true;
            } else if (target < array[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = int(matrix.size());
        if (0 == m) {
            return false;
        }
        int n = int(matrix[0].size());
        if (0 == n) {
            return false;
        }
        for (int i = 0; i < m; ++i) { // 遍历行。
            if (target <= matrix[i][n - 1] && target >= matrix[i][0]) {
                return this->binarySearch(target, matrix[i]);
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
