//
// Created by 王阳 on 2018/3/27.
//

/*
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */
#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res;  // 记录整个链表。

        bool flag = false;  // 标记进位，最开始没有。

        // 长度相等。
        while (l1->next != NULL && l2->next != NULL) {
            int result = 0;

            if (flag) {
                result++; // 进位。
                flag = false; // 使用进位。
            }

            result = result + l1->val + l2->val;

            if (result >= 10) {
                flag = true;
                result = result - 10;
            } else {
                flag = false;
            }
            insert(res, result);
            l1 = l1->next;
            l2 = l2->next;
        }

        int res1 = 0;

        // 如果长度相等，还有进位的时候。
        if (flag) {
            res1++;
        }

        while (l1 != NULL) {
            if (flag) {
                insert(res, l1->val + 1);
            }
        }

        return res;
    }

    /**
     * 在链表的尾部插入一个新的节点。
     * @param l 链表。
     * @param val 值。
     */
    void insert(ListNode *l, int val) {
        while (l != NULL) {
            l = l->next;
        }
        l = new ListNode(val);
    }
};