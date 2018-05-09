//
// Created by 王阳 on 2018/5/9.
//

#include "header.h"

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res;
        int n = int(S.size());
        // std::cout << "n = " << n << std::endl;
        for (int i = 0; i < n; i++) {
            res.push_back(-1);
        }

        // 设置为0.
        for (int i = 0; i < n; i++) {
            if (S[i] == C) {
                res[i] = 0;
            }
        }

        // for (auto x: res) {
        // std::cout << "x = " << x << std::endl;
        // }

        for (int i = 0; i < n; i++) {
            if (0 == res[i]) {
                continue;
            }
            // 向左。
            int j = i - 1;
            int min_1 = INT_MAX;
            while (j >= 0) {
                if (0 == res[j]) {
                    min_1 = i - j;
                    break;
                }
                j--;
            }
            // 向右。
            int min_2 = INT_MAX;
            int k = i + 1;
            while (k < n) {
                if (0 == res[k]) {
                    min_2 = k - i;
                    break;
                }
                k++;
            }
            res[i] = min(min_1, min_2);
            // std::cout << i << " = " << res[i] << std::endl;
            // std::cout << "min_1 = " << min_1 << std::endl;
            // std::cout << "min_2 = " << min_2 << std::endl;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    string s = "loveleetcode";
    char C = 'e';
    solution->shortestToChar(s, C);
    return 0;
}