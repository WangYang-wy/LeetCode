//
// Created by 王阳 on 2018/7/28.
//

#include "header.h"

//new二维数组版本
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = (int) word1.length() + 1;
        int len2 = (int) word2.length() + 1;
        int **p = new int *[len1];
        if (!p) {
            return 0;
        }

        for (int i = 0; i < len1; i++) {
            p[i] = new int[len2];
            if (!p[i]) {
                return 0;
            }
        }

        for (int i = 0; i < len1; i++) {
            p[i][0] = i;
        }

        for (int j = 0; j < len2; j++) {
            p[0][j] = j;
        }

        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                int tmp_step;
                // 判断是否相等，如果相等，那么可以直接跳过，否则，考虑替换。
                if (word1[i - 1] == word2[j - 1]) {
                    tmp_step = 0 + p[i - 1][j - 1];
                } else {
                    tmp_step = 1 + p[i - 1][j - 1];
                }

                // 删除或者增加。
                int tmp_step2 = 1 + min(p[i - 1][j], p[i][j - 1]);
                p[i][j] = min(tmp_step2, tmp_step);
            }
        }
        int return_val = p[len1 - 1][len2 - 1];

        for (int i = 0; i < len1; i++) {
            delete p[i];
        }
        delete[] p;
        return return_val;
    }
};


int main() {
    Solution *solution = new Solution();
    std::cout << solution->minDistance("spartan", "part") << std::endl;
    return 0;
}
