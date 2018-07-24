//
// Created by 王阳 on 2018/7/24.
//

#include "header.h"

class Solution {
private:
    stack<int> counts; // 存储倍数。
    stack<int> digits; // 存储字符，后面累计转换成倍数。
    stack<int> left_index; // 存储 [ 的索引值。
public:
    string sub_string(string sub_str, int times) {
        string res;
        for (int i = 0; i < times; ++i) {
            res += sub_str;
        }
        return res;
    }

    string decodeString(string s) {
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] <= '9' && s[i] >= '0') {
                digits.push(int(s[i] - '0'));
                s.erase(i, 1);
                i--;
            } else if ('[' == s[i]) {
                left_index.push(i);
                int times = digits.top();
                digits.pop();
                int k = 10;
                while (!digits.empty()) {
                    times = times + digits.top() * k;
                    k *= 10;
                    digits.pop();
                }
                counts.push(times);
            } else if (']' == s[i]) {
                int times = counts.top();
                counts.pop();
                int start = left_index.top();
                left_index.pop();
                int end = i;
                string tmp;
                for (int j = start + 1; j < end; ++j) {
                    tmp += s[j];
                }
                s = s.substr(0, start) + this->sub_string(tmp, times) + s.substr(end + 1);
                i = i - 2; // 去除 [、]。
            }
        }
        return s;
    }
};

int main() {
    Solution *solution = new Solution();
//    string s = "100[leetcode]";
    string s = "2[a]3[b]4[c]5[d]";
//    string s = "3[a]2[bc]";
    std::cout << solution->decodeString(s) << std::endl;
    int start = 1;
    int end = 3;
//    std::cout << s.substr(0, start) << std::endl;
//    std::cout << s.substr(end + 1);
//    int len = end - start - 1;
//    int times = 2;
//    s.erase(start - 2, end - start + 2);
//    std::cout << s << endl;
//    for (int i = 0; i < times; i++) {
//        s.insert(start - 2, "c");
//    }
//    std::cout << s << endl;

    return 0;
}
