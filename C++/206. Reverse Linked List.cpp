//
// Created by 王阳 on 2018/4/15.
//

#include "header.h"
/**
 * Reverse a singly linked list.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *head) {
        int res = 0;
        while (head) {
            head = head->next;
            res++;
        }
        return res;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *temp = head;
        if (head == NULL || head->next == NULL) { // 只有一个结点或者空，不需要翻转。
            return head;
        }

        int n = getLength(head);
        ListNode *last;
        while (temp->next) {
            temp = temp->next;
        }
        last = temp;

        ListNode *res = last;
        last->next = head;
        head = head->next;
        last->next->next = NULL;
        for (int i = 1; i < n - 1; i++) {
            ListNode *tmp = last->next;
            last->next = head;
            head = head->next;
            last->next->next = tmp;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *res = new ListNode(1);
    res->next = new ListNode(2);
    res->next->next = new ListNode(3);
    ListNode *ress = solution->reverseList(res);
    print_list(ress);
    return 0;
}