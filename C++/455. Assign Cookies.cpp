//
// Created by 王阳 on 2018/5/13.
//

#include "header.h"

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        // 先排序。
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_index = 0;
        int s_index = 0;
        int g_length = int(g.size());
        int s_length = int(s.size());
        while (g_index < g_length && s_index < s_length) {
            if (g[g_index] <= s[s_index]) {
                g_index++;
            }
            s_index++;
        }
        return g_index;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}