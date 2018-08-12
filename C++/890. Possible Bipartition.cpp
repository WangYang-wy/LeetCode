//
// Created by 王阳 on 2018/8/12.
//

#include "header.h"

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        vector<int> color(N, 0);
        unordered_map<int, vector<int>> edges;

        for (auto item:dislikes) { // 邻接表。
            edges[item[1] - 1].push_back(item[0] - 1);
            edges[item[0] - 1].push_back(item[1] - 1);
        }
        for (int i = 0; i < N; ++i) {
            if (color[i] == 0) { // color is 0::Unvisited, 1::red, 2::blue
                int col = 1;
                color[i] = col;
                stack<int> s;
                s.push(i);

                while (!s.empty()) {
                    int t = s.top();
                    s.pop();
                    // 填写颜色，如果填写了 1，那么就填写 2。
                    col = (color[t] == 1) ? 2 : 1;   // Flip the color
                    for (auto elem:edges[t]) {  // 遍历 t 的每条边。
                        if (color[elem] == 0) { // 如果没有选择，那么选择另一个颜色。
                            color[elem] = col;
                            s.push(elem); // 然后压栈。
                        } else if (color[elem] != col) // 如果颜色不是期望的，则冲突。
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}