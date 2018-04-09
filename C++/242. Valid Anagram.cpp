//
// Created by 王阳 on 2018/4/3.
//

/**
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * Follow up:
 * What if the inputs contain unicode characters?
 * How would you adapt your solution to such case?
 *
 * 由颠倒字母顺序而构成的字。
 */

#include "header.h"

/**
 * 参考博客：https://blog.csdn.net/fly_yr/article/details/49886391
 * 主要问题在于，可以使用STL的字符串：字符数据进行排序，然而我选择自己实现排序算法，导致TLE。
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_length = int(s.length());
        int t_length = int(t.length());
        if (s_length == t_length) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        } else {
            return false;
        }
    }

    string sort_str(string s) { // 一个选择排序。
        string tmp;
        int length = int(s.length());
        vector<char> my_str;
        for (int i = 0; i < length; i++) {
            my_str.push_back(s[i]);
        }

        for (int i = 0; i < length; i++) {
            int index = -1;
            char pivot = 40;
            for (int j = 0; j < length - i; j++) {
                if (my_str[j] > pivot) { // 只看没有被选择的。
                    index = j;
                    pivot = my_str[j];
                }
            }
            tmp = tmp + my_str[index];
            my_str.erase(my_str.begin() + index);
        }
        return tmp;
    }
};

int main() {
    Solution *solution = new Solution();
    string s = "anagram";
//    solution->isAnagram("anagram", "nagaram");
//    string ss = solution->sort_str(s);
    printf("%d\n", solution->isAnagram("anagram", "nagaram"));
//    printf("%d\n", solution->isAnagram("anagram", "nagarama"));
//    printf("s_sort = %s\n", solution->sort_str("nagaram").c_str());
//    printf("s_sort = %s\n", solution->sort_str("anagram").c_str());
//    printf("%s\n", solution->sort_str("anagram").c_str());
//    printf("%s\n", ss.c_str());
    return 0;
}