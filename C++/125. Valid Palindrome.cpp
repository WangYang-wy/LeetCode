//
// Created by 王阳 on 2018/3/28.
//

/*
 * Given a string, determine if it is a palindrome,
 * considering only alphanumeric characters and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * Note:
 * Have you consider that the string might be empty?
 * This is a good question to ask during an interview.
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

/**
 * 参考博客：https://blog.csdn.net/booirror/article/details/43197845
 */

#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isAlphanumeric(const char c) {
        if ('A' <= c && c <= 'Z')
            return true;
        else if ('a' <= c && c <= 'z')
            return true;
        else if ('0' <= c && c <= '9')
            return true;
        return false;
    }

    char toLower(const char c) {
        if ('A' <= c && c <= 'Z')
            return 'a' + c - 'A';
        return c;
    }

    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int begin = 0;
        int end = int(s.size() - 1);
        // 左右两边开始循环，快速排序的思想，两个哨兵。
        while (true) {
            while (begin < s.size() && !isAlphanumeric(s[begin])) {
                begin++;
            }
            while (end >= 0 && !isAlphanumeric(s[end])) {
                end--;
            }
            if (end <= begin)
                return true;
            if (toLower(s[begin]) != toLower(s[end])) {
                return false;
            }
            begin++;
            end--;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    string s("a.");
    char stmp = '.';
    printf("res = %d\n", solution->isPalindrome(s));
//    printf("res = %d\n", solution->getChar(stmp));
    return 0;
}