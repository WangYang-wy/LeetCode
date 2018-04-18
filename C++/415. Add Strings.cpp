//
// Created by 王阳 on 2018/4/18.
//

#include "header.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int n_1 = int(num1.size());
        int n_2 = int(num2.size());
        int min_length = n_1 < n_2 ? n_1 : n_2;

        int flag = 0;

        int i = n_1 - 1;
        int j = n_2 - 1;
        while (i >= 0 && j >= 0) {
            int bit = char2int(num1[i]) + char2int(num2[j]) + flag;
            flag = 0;

            if (bit > 9) {
                bit = bit % 10;
                flag = 1;
            }
            res = to_string(bit) + res;
            i--;
            j--;
        }

        while (i >= 0) {
            int bit = char2int(num1[i]) + flag;
            flag = 0;

            if (bit > 9) {
                bit = bit % 10;
                flag = 1;
            }
            res = to_string(bit) + res;
            i--;
        }

        while (j >= 0) {
            int bit = char2int(num2[j]) + flag;
            flag = 0;

            if (bit > 9) {
                bit = bit % 10;
                flag = 1;
            }
            res = to_string(bit) + res;
            j--;
        }

        if (flag) {
            res = '1' + res;
        }
        return res;
    }

    int char2int(char ch) {
        return int(ch - 48);
    }
};

int main() {
    Solution *solution = new Solution();
//    std::cout << solution->addStrings("111", "111") << std::endl;
    std::cout << solution->addStrings("3876620623801494171", "6529364523802684779") << std::endl;
    return 0;
}