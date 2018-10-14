//
// Created by 王阳 on 2018/10/14.
//

#include "header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *findLast(ListNode *head) {
        ListNode *res = nullptr;
        while (head->next) { // 如果有下一个。
            res = head;
            head = head->next;
        }
        ListNode *tmp = res->next;
        res->next = nullptr;
        return tmp;
    }

    int get_length(ListNode *head) {
        int i = 0;
        while (head) { // 如果有下一个。
            i++;
            head = head->next;
        }
        return i;
    }

public:
    void reorderList(ListNode *head) {
        ListNode *node = head;
        int len = this->get_length(head);
        int i = 0;
        while (i < len / 2) {
            i++;
            ListNode *last = this->findLast(node); // 最后一个结点。
            ListNode *next = node->next;
            last->next = node->next;
            node->next = last;
            node = next;
        }
    }
};

int main() {
    return 0;
}