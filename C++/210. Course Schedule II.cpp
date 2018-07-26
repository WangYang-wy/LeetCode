//
// Created by 王阳 on 2018/7/25.
//

#include "header.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        stack<int> st;
        vector<int> order;

        vector<pair<int, int>> link_list; // 统计课程的前置要求个数。

        for (int i = 0; i < numCourses; ++i) {
            link_list.push_back(make_pair(i, 0)); // 先初始化，设置每个课程都没有前置课程。
        }

        for (auto x : prerequisites) {
            link_list[x.first].second += 1; // 前置课程个数。
        }

        for (int i = 0; i < numCourses; ++i) {
            if (0 == link_list[i].second) {
                st.push(i); // 栈中存储入度为 0 的课程。
                order.push_back(i);
            }
        }

        while (!st.empty()) {
            int course_id = st.top(); // 取出一个没有先修课程的 id 号。
            st.pop();
            for (pair<int, int> x : prerequisites) {
                if (course_id == x.second) { // 是某一门课的前置课程。
                    link_list[x.first].second -= 1; // 这门课的入度减一。
                    if (0 >= link_list[x.first].second) { // 如果入度减为 0，那么可以学习该课程，加入栈中。
                        st.push(x.first);
                        order.push_back(x.first);
                    }
                }
            }
        }
        if (order.size() != numCourses) {
            order.clear();
        }

        return order;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    solution->findOrder(2, prerequisites);
    return 0;
}