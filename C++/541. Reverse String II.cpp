//
// Created by 王阳 on 2018/5/11.
//

#include "header.h"

/**
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k characters
 * and left the other as original.
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        int pos = 0;
        while (pos < s.size()) {
            if (pos + k > s.size()) {
                k = s.size() - pos;
            }
            string tmpStr = s.substr(pos, k);
            reverse(tmpStr.begin(), tmpStr.end());
            s.replace(pos, k, tmpStr);
            pos += 2 * k;
        }
        return s;
    }
};

int main() {
    Solution *solution = new Solution();
    delete solution;
    return 0;
}