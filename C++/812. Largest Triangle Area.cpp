//
// Created by 王阳 on 2018/5/1.
//

#include "header.h"

class Solution {
public:
    double largestTriangleArea(vector <vector<int>> &points) {
        int n = int(points.size());
        double max_area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    // 向量叉积运算，需要求一个绝对值。
                    double area = abs(points[i][0] * points[j][1] + points[j][0] * points[k][1] +
                                      points[k][0] * points[i][1] -
                                      points[j][0] * points[i][1] - points[k][0] * points[j][1] -
                                      points[i][0] * points[k][1]) / 2.0;

                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }
        return max_area;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}