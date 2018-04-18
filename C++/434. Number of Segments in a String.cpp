//
// Created by 王阳 on 2018/4/18.
//

#include "header.h"

/**
 * Count the number of segments in a string, where a segment is defined
 * to be a contiguous sequence of non-space characters.
 * Please note that the string does not contain any non-printable characters.
 */
class Solution {
public:
    int countSegments(string s) {
        int n = int(s.length());
        int begin = -1;
        int end = n;
        int i;
        for (i = 0; i < n; i++) {
            if (s[i] != ' ') {
                begin = i;  // 第一个单词的第一个字母的索引。
                break;
            }
        }
        if (i == n) {
            return 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                end = i; // 最后一个单词的最后一个字母的索引。
                break;
            }
        }

        if (begin >= end) { // 都是索引。
            return 0;
        }

        int count = 1;
        for (int i = begin; i <= end; i++) {
            if (s[i] == ' ' && s[i + 1] != ' ' && i < end) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution *solution = new Solution();
    std::cout << solution->countSegments("                ") << std::endl;
    return 0;
}