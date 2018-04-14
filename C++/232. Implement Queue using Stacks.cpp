//
// Created by 王阳 on 2018/4/14.
//

#include "header.h"

class MyQueue {
public:

    stack<int> *st;

    /** Initialize your data structure here. */
    MyQueue() {
        st = new stack<int>();
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> *temp = new stack<int>();
        while (!this->st->empty()) {
            int a = this->st->top();
            this->st->pop();
            temp->push(a);
        }

        this->st->push(x);
        while (!temp->empty()) {
            int a = temp->top();
            temp->pop();
            this->st->push(a);
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int a = this->st->top();
        this->st->pop();
        return a;
    }

    /** Get the front element. */
    int peek() {
        return this->st->top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return this->st->empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main() {
//    Solution *solution = new Solution();
    return 0;
}