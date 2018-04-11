//
// Created by 王阳 on 2018/4/11.
//

#include "header.h"

/**
 * Given a pattern and a string str, find if str follows the same pattern.
 * Here follow means a full match, such that there is a bijection between
 * a letter in pattern and a non-empty word in str.
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 * Credits:
 * Special thanks to @minglotus6 for adding this problem and creating all test cases.
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = int(pattern.length());
        vector<string> vector_str = split(str);
        int n_str = int(vector_str.size());
        if (n != n_str) {
            return false;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                std::cout << "pattern[i] = " << pattern[i] << std::endl;
                std::cout << "pattern[j] = " << pattern[j] << std::endl;
                std::cout << "vector_str[i] = " << vector_str[i] << std::endl;
                std::cout << "vector_str[j] = " << vector_str[j] << std::endl;

                // 同时相等，或者同时不等。
                if (((pattern[i] == pattern[j]) && (vector_str[i] == vector_str[j])) ||
                    ((pattern[i] != pattern[j]) && (vector_str[i] != vector_str[j]))) { ;
                } else {
                    return false;
                }
            }
        }

        return true;
    }

    vector<string> split(string str) {
        vector<string> res;
        int length = int(str.length());
        int index = 0;
        for (int i = 0; i < length - 1; i++) {
            if (str[i] == ' ') {
                res.push_back(str.substr(index, i - index));
//                std::cout << "sub string = " << str.substr(index, i - index) << '.' << std::endl;
                index = i + 1;
            }
        }
        res.push_back(str.substr(index));
//        std::cout << "sub string = " << str.substr(index) << '.' << std::endl;
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    for (auto x : solution->split("dog cat cat dog")) {
        std::cout << x << std::endl;
    }
    solution->wordPattern("abba", "dog cat cat dog");

    return 0;
}