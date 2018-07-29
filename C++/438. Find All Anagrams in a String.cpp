//
// Created by 王阳 on 2018/7/29.
//

#include "header.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res, m(256, 0);
        int left = 0, right = 0, cnt = int(p.size()), n = int(s.size());
        for (char c : p) ++m[c];
        while (right < n) {
            if (m[s[right++]]-- >= 1) {
                --cnt;
            }
            if (cnt == 0) {
                res.push_back(left);
            }
            if (right - left == p.size() && m[s[left++]]++ >= 0) {
                ++cnt;
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}
