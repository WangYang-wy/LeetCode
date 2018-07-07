//
// Created by 王阳 on 2018/3/28.
//

/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * Example:
 * Input: "Hello World"
 * Output: 5
 */

#include "header.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = int(s.length());
        int true_length = length;
        int size = 0;
        int index = 0;

        // 清除所有的无效空格。
        for (int i = length - 1; i >= 0; i--) {
            if (' ' == s[i]) {
                true_length--;
            } else {
                break;
            }
        }

        printf("true_length = %d\n", true_length);

        // 记录单词字符数。
        for (int i = true_length - 1; i >= 0; i--) {
            if (' ' != s[i]) {
                size++;
            } else {
                break;
            }
        }
        return size;
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%d\n", solution->lengthOfLastWord("        "));
    printf("%d\n", solution->lengthOfLastWord("Hello World"));
    return 0;
}
