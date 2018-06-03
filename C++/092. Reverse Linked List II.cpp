//
// Created by 王阳 on 2018/6/3.
//

#include"header.h"

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int change_len = n - m + 1; // 计算需要逆置结点的个数。
        ListNode *pre_head = NULL; // 初始化开始逆置的结点的前驱。
        ListNode *result = head; // 最终置换后的链表头结点，非特殊情况为head。
        while (head && --m) {
            pre_head = head; // 设置逆序子序列的前面一个结点。
            head = head->next;
        }

        ListNode *modify_list_tail = head; // 修改结点的位置，此时head指向修改子序列中的第一个结点。
        ListNode *new_head = NULL;
        while (head && change_len) {
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
            change_len--;
        }

        modify_list_tail->next = head; // new_head指向修改子序列的最后一个结点。

        if (pre_head) { // 如果不为空，则说明不是从第一个结点开始逆序的。
            pre_head->next = new_head;
        } else {
            result = new_head;
        }
        return result;
    }
};