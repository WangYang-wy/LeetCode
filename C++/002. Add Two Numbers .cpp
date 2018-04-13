//
// Created by 王阳 on 2018/4/13.
//
/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */
#include "header.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *head = new ListNode(0);

        ListNode *tail = head;

        int carry = 0;

        while (l1 || l2 || carry) {
            int n = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            tail->next = new ListNode(n % 10);
            carry = n / 10;
            tail = tail->next;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return head->next;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}

