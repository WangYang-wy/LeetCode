//
// Created by 王阳 on 2018/4/9.
//

#include "header.h"

/**
 * The count-and-say sequence is the sequence of integers with the first five terms
 * as following:
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * Note: Each term of the sequence of integers will be represented as a string.
 * Example 1:
 * Input: 1
 * Output: "1"
 * Example 2:
 * Input: 4
 * Output: "1211"
 */
class Solution {
public:
    string countAndSay(int n) {
        if (1 == n) {
            return "1";
        }

        string tmp = countAndSay(n - 1);
        string res;
        int length = int(tmp.size());
        int count = 1;
        for (int i = 0; i < length; i++) {
            if (tmp[i] == tmp[i + 1]) {
                count++;
                continue;
            } else {
                res = res + to_string(count) + tmp[i];
                count = 1;
            };
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    printf("%s\n", solution->countAndSay(1).c_str());
    printf("%s\n", solution->countAndSay(2).c_str());
    printf("%s\n", solution->countAndSay(3).c_str());
    printf("%s\n", solution->countAndSay(4).c_str());
    printf("%s\n", solution->countAndSay(5).c_str());
    return 0;
}