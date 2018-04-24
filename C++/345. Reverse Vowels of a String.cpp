//
// Created by 王阳 on 2018/4/24.
//

#include "header.h"
/**
 * Write a function that takes a string as input and reverse only the vowels of a string.
 * Example 1:
 * Given s = "hello", return "holle".
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 * Note:
 * The vowels does not include the letter "y".
 */

// a e i o u.

class Solution {
public:
    string reverseVowels(string s) {
        int n = int(s.length());
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            while (true) {
                if (!isVowels(s[start])) {
                    start++;
                } else {
                    break;
                }
            }

            while (true) {
                if (!isVowels(s[end])) {
                    end--;
                } else {
                    break;
                }
            }

            if (start <= end) {
                char tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
                start++;
                end--;
            }
        }
        return s;
    }

    bool isVowels(char ch) {
        if ('a' == ch || 'e' == ch || 'i' == ch || 'o' == ch || 'u' == ch
            || 'A' == ch || 'E' == ch || 'I' == ch || 'O' == ch || 'U' == ch) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution *solution = new Solution();
    solution->reverseVowels("hello");
    return 0;
}