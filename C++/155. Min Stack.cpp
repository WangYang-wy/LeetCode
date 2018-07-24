//
// Created by 王阳 on 2018/4/11.
//

#include "header.h"

class MinStack {
private:
    vector<int> *a;
public:
    MinStack() {
        a = new vector<int>();
    }

    void push(int x) {
        a->push_back(x);
    }

    void pop() {
        a->pop_back();
    }

    int top() {
        return (*a)[a->size() - 1];
    }

    int getMin() {
        int n = int(a->size());
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if ((*a)[i] < res) {
                res = (*a)[i];
            }
        }
        return res;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
//    Solution *solution = new Solution();
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin();  // --> Returns -3.
    minStack.pop();
    std::cout << minStack.top();      //--> Returns 0.
    std::cout << minStack.getMin();   //--> Returns -2.
    return 0;
}
