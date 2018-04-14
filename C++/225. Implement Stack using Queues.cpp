//
// Created by 王阳 on 2018/4/14.
//

#include "header.h"

class MyStack {
public:
    queue<int> *q;

    /** Initialize your data structure here. */
    MyStack() {
        q = new queue<int>();
    }

    /** Push element x onto stack. */
    // 先将一个数字压入栈中，然后这个数字之前的所有数字全部依次出队，入队，这样，这个数字的位置就处于了队头。
    void push(int x) {
        this->q->push(x);
        for (int i = 0; i < q->size() - 1; ++i) {
            q->push(q->front());
            q->pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = this->q->front();
        this->q->pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        return this->q->front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return this->q->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main() {
//    Solution *solution = new Solution();

    return 0;
}