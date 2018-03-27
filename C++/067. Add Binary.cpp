//
// Created by 王阳 on 2018/3/27.
//

/*
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int a_length = int(a.length());
        int b_length = int(b.length());
        string res = NULL;

        bool flag = false; // 最开始没有进位。
        int i = 0;
        for (; i < a_length && i < b_length; i++) {
            int result = 0;
            if (flag) { // 有进位。
                result++;
                flag = false;
            }

            result = int(a[i]) + int(b[i]) + result;

            if (result > 1) {
                result = result - 2;
                flag = true;
            }
            res = res + char(result);
        }

        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    string s1("11");
    string s2("11");
//    string s1 = "11";
//    string s2 = "11";
//    s1.c_str();
//    s2.c_str();
    printf("%s\n", solution->addBinary(s1, s2));
}