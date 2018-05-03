//
// Created by 王阳 on 2018/5/3.
//

#include "header.h"

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        int L = int(sqrt(area));
        while (0 != (double(area) / double(L)) - int(area / L)) {
            L--;
        }
        double result_1 = double(area / L);
        double result = (double(area) / double(L)) - int(area / L);
        L = L > area / L ? L : area / L;
        res.push_back(L);
        res.push_back(area / L);
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    solution->constructRectangle(5);
    std::cout << double(5) / double(2) << std::endl;
    delete solution;
    return 0;
}