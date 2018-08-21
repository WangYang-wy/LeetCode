//
// Created by 王阳 on 2018/8/21.
//

#include "header.h"

class MyStack {
private:
    vector<char> s;
public:
    void push(char x) {
        if ('#' == x) {
            this->pop();
        } else {
            s.push_back(x);
        }
    }

    void pop() {
        if (0 != s.size()) {
            s.pop_back();
        }
    }

    string toStr() {
        string tmp;
        for (auto x:s) {
            tmp += x;
        }
        return tmp;
    }
};

class Solution {
private:

public:
    bool backspaceCompare(string S, string T) {
        MyStack s, t;
        for (auto x:S) {
            s.push(x);
        }

        for (auto x:T) {
            t.push(x);
        }

        return s.toStr() == t.toStr();
    }
};

int main() {
    return 0;
}