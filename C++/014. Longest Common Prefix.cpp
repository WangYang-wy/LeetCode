//
// Created by 王阳 on 2018/3/28.
//

/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

#include "header.h"

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return ""; // 如果没有字符串。
        }
        char *str = (char *) malloc(sizeof(char) * (strs[0].size() + 1));

        for (int i = 0; i < strs[0].size(); i++) {
            str[i] = strs[0][i];
        }

        str[strs[0].size()] = 0; // 设置终结符。

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (str[j] && strs[i][j] && str[j] == strs[i][j]) {
                j++; // 循环每个字符串。
            }
            str[j] = 0; // 从左到右开始判断是否相等。
        }
        return string(str);
    }

    /**
     * 本地无错，提交LeetCode有错。
     * @param strs 字符串数组。
     * @return 最长公共子序列。
     */
    string longestCommonPrefix_ERROR(vector<string> &strs) {
        printf("length = %d\n", strs.size());
        if (0 == strs.size()) {
            return "";
        } else if (1 == strs.size()) { // 如果只有一个字符串，那么直接返回。
            return strs[0];
        } else { // 字符串数组，大于等于2个。
            int index = 0;
            for (int i = 0; i < strs[0].length(); i++) {
                int flag = 0;
                for (int j = 1; j < strs.size(); j++) {
                    if (strs[0][i] != strs[j][i]) {
                        flag = 1; // 表示不匹配了。
                        break;
                    }
                }

                if (0 == flag) {
                    index++;
                }
            }
            printf("index = %d\n", index);

            string res = "";
            for (int i = 0; i < index; i++) {
                res = res + strs[0][i];
            }

            return res;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    vector<string> *a = new vector<string>();
    string s1 = "abab";
    string s2 = "aba";
    string s3 = "";
    a->push_back(s1);
    a->push_back(s2);
    a->push_back(s3);
    printf("%s\n", solution->longestCommonPrefix(*a).c_str());
    return 0;
}