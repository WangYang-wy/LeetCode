//
// Created by 王阳 on 2018/10/14.
//

#include "header.h"

class Solution {
private:
    vector<string> res;
    int n;
    vector<char> flag;
    int target;

    int compute(string &expression) {
        vector<int> nums;
        vector<char> ops;
        int length = int(expression.length());
        int i = 0, tmp = 0;

        while (i < length) {
            if (i > 0 && ('-' == expression[i] || '+' == expression[i] || '*' == expression[i])) {
                nums.push_back(tmp);
                ops.push_back(expression[i]);
                tmp = 0;
            } else {
                tmp = tmp * 10 + int(expression[i] - 48);
            }
            i++;
        }

        while (1 != nums.size()) {
            int a = nums.back();
            nums.pop_back();
            int b = nums.back();
            nums.pop_back();
            char op = ops.back();
            ops.pop_back();

            if ('+' == op) {
                nums.push_back(a + b);
            } else if ('-' == op) {
                nums.push_back(a - b);
            } else {
                nums.push_back(a * b);
            }
        }

        return nums[0];
    }

    void search(int idx, string &num) {
        if (idx == n - 1) { // 符号搜索一共有 n - 1 个。
            // 记录。
            //  生成表达式。
            string expression;
            expression += num[0];
            for (int i = 0; i < n - 1; ++i) {
                if ('+' == this->flag[i]) {
                    expression += '+';
                    expression += num[i + 1];
                } else if ('-' == this->flag[i]) {
                    expression += '-';
                    expression += num[i + 1];
                } else if ('*' == this->flag[i]) {
                    expression += '*';
                    expression += num[i + 1];
                } else {
                    expression += num[i + 1];
                }

//                this->res.push_back(expression);
            }
            if (this->target == this->compute(expression)) {
                this->res.push_back(expression);
            }
//            std::cout << expression << std::endl;
            return;
        }

        this->flag[idx] = '0';
        search(idx + 1, num);

        this->flag[idx] = '+';
        search(idx + 1, num);

        this->flag[idx] = '-';
        search(idx + 1, num);

        this->flag[idx] = '*';
        search(idx + 1, num);
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        addOperatorExpression(num, target, 0, 0, "", res);
        return res;
    }

    void addOperatorExpression(string num, int target, long long diff,
                               long long curNum, string out, vector<string> &res) {
        //两个变量diff和curNum，一个用来记录将要变化的值，另一个是当前运算后的值当前运算后的值，而且它们都需要用long     long型的，因为字符串转为int型很容易溢出，所以我们用长整型。
        if (num.length() == 0 && curNum == target) {
            res.push_back(out);
        }
        // 字符串全添加了操作符，等于 target 就放进vector。
        for (int i = 1; i <= num.length(); i++) {
            string cur = num.substr(0, i);
            if (cur.length() > 1 && cur[0] == '0') {
                return;// 有 0 开头的字符串出现，明显这不是数字，
            }
            string next = num.substr(i);
            if (out.length() > 0) {
                /*对于加和减，diff就是即将要加上的数和即将要减去的数的负值，而对于乘来说稍有些复杂，此时的diff应该是上一次的变化的diff乘以即将要乘上的数，有点不好理解，那我们来举个例子，比如2+3*2，即将要运算到乘以2的时候，上次循环的curNum = 5, diff = 3, 而如果我们要算这个乘2的时候，新的变化值diff应为3*2=6，而我们要把之前+3操作的结果去掉，再加上新的diff，即(5-3)+6=8，即为新表达式2+3*2的值，有点难理解，大家自己一步一步推算吧。*/
                addOperatorExpression(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
                addOperatorExpression(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
                addOperatorExpression(next, target, diff * stoll(cur), curNum - diff + diff * stoll(cur),
                                      out + "*" + cur, res);
            } else {
                addOperatorExpression(next, target, stoll(cur), stoll(cur), cur, res);//刚开始计算时
            }
        }

    }

    vector<string> addOperators_ERROR(string num, int target) {
        this->target = target;
        res.clear();
        flag.clear();
        n = int(num.length());
        if (0 == n) {
            return this->res;
        }

        for (int i = 1; i < n; ++i) {
            this->flag.push_back('0'); // 0 是不作为。
        }

        this->search(0, num);
        return this->res;
    }
};

int main() {
    return 0;
}