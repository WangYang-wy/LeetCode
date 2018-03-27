//
// Created by 王阳 on 2018/3/27.
//

/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid. The brackets must close in the correct order,
 * "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int length = int(s.length());
//        printf("length = %d\n", length);
        vector<char> stack;
        for (int i = 0; i < length; i++) {
            if (s[i] == '(') {
                stack.push_back(s[i]);
            } else if (s[i] == ')') {
                if (0 != stack.size() && stack.back() == '(') {
                    stack.pop_back();
                } else {
                    return false;
                }
            } else if (s[i] == '[') {
                stack.push_back(s[i]);
            } else if (s[i] == ']') {
                if (0 != stack.size() && stack.back() == '[') {
                    stack.pop_back();
                } else {
                    return false;
                }
            } else if (s[i] == '{') {
                stack.push_back(s[i]);
            } else if (s[i] == '}') {
                if (0 != stack.size() && stack.back() == '{') {
                    stack.pop_back();
                } else {
                    return false;
                }
            }
        }

        if (0 == stack.size()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%d\n", solution->isValid("]"));
    return 0;
}