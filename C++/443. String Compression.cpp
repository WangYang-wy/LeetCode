//
// Created by 王阳 on 2018/5/8.
//

#include "header.h"

/**
 * Given an array of characters, compress it in-place.
 * The length after compression must always be smaller than or equal to the original array.
 * Every element of the array should be a character (not int) of length 1.
 * After you are done modifying the input array in-place, return the new length of the array.
 * @return
 */

class Solution {
public:
    int compress(vector<char> &chars) {
        int temp = chars[0];
        int pre = 0; // index.
        int k = 1; // 相同的个数。
        int n = int(chars.size()); // 个数。
        for (int i = 1; i < n; i++) {
            if (chars[i] == temp) {
                k++; // 相同。
            }

            if (chars[i] != temp) {
                chars[pre] = temp;

                if (k > 1) {
                    string s = to_string(k); // 插入连续的频数。
                    for (int j = 0; j < s.size(); j++, pre++) {
                        chars[pre + 1] = s[j];
                    }
                    pre++;
                } else { // 如果k=1，则不写频数。
                    pre++;
                }
                k = 1;
                temp = chars[i]; // 确定新的开始。
            }
        }

        chars[pre] = temp;

        // 对于最后一个的处理。
        if (k > 1) {
            string s = to_string(k);
            for (int i = 0; i < s.size(); i++, pre++) {
                chars[pre + 1] = s[i];
            }
        }

        // 对于多余的。
        for (int i = pre + 1; i < n; i++) {
            chars.pop_back();
        }

        return chars.size();
    }

    int compress_error(vector<char> &chars) {
        int n = int(chars.size());
        vector<char> char_tmp(chars);
        chars.clear();

        vector<char> res;
        // int index = 0;
        for (int i = 0; i < n; i++) {
            if (n - 1 == i) {
                res.push_back(chars[i]);
            }

            for (int j = i + 1; j < n; j++) {
                if (char_tmp[j] == char_tmp[i] && j == n - 1) {
                    res.push_back(char_tmp[i]);
                    int num = j - i + 1;
                    int base = int(log10(num));
                    if (1 == num) {
                        break;
                    }
                    while (base >= 0) {
                        int power = pow(10, base);
                        std::cout << "char(num / power + 48) = " << char(num / power + 48) << std::endl;
                        res.push_back(char(num / power + 48));
                        num = num % power;
                        base--;
                    }
                    return int(res.size());
                } else if (char_tmp[j] == char_tmp[i]) {
                    continue;
                } else {
                    int num = j - i;
                    std::cout << "num = " << num << std::endl;

                    // index = j;
                    res.push_back(char_tmp[i]);
                    if (1 == num) {
                        break;
                    }
                    int base = int(log10(num));
                    while (base >= 0) {
                        int power = pow(10, base);
//                        res += to_string(num / power);
                        std::cout << "char(num / power + 48) = " << char(num / power + 48) << std::endl;
                        res.push_back(char(num / power + 48));
                        num = num % power;
                        base--;
                    }
                    i = j - 1;
                }
            }
        }
        return int(res.size());
    }
};

int main() {
    Solution *solution = new Solution();
    vector<char> chars;
    chars.push_back('a');
    chars.push_back('a');
    std::cout << solution->compress(chars) << std::endl;
    return 0;
}