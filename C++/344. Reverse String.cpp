//
// Created by 王阳 on 2018/3/27.
//

/*
 * Write a function that takes a string as input and
 * returns the string reversed.
 * Example:
 * Given s = "hello", return "olleh".
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int length = int(s.length());
        int i = 0;
        int j = length - 1;
        while (i < j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
};

int main() {
    Solution *solution = new Solution();
    string s("hello");
    printf("%s\n", solution->reverseString(s));
    return 0;
}