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
    int getLength(ListNode *head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        return n;
    }

    ListNode *getNth(ListNode *head, int k) {
        int i = 0;
        while (i < k && head) {
            i++;
            head = head->next;
        }
        return head;
    }

    ListNode *getLast(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *res;
        while (head->next) { // 如果还有下一个。
            res = head;
            head = head->next;
        }
        ListNode *tmp = res->next;
        res->next = nullptr;
        return tmp;
    }

public:
    ListNode *rotateRight(ListNode *head, int k) {
        int n = this->getLength(head);
        if (0 == n || 1 == n) {
            return head;
        }
        k = k % n;
        ListNode *last;
        for (int i = 0; i < k; ++i) {
            last = this->getLast(head);
            last->next = head;
            head = last;
        }
        return head;
    }
};

int main() {
    return 0;
}