//
// Created by 王阳 on 2018/3/30.
//

#include "header.h"

//Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 存在的问题。
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *curr = head;
        int length = getLength(head);
        // 处理头。
        if (1 == length) {
            return NULL;
        }

        // 处理尾。
        if (n == length) {
            return head->next;
        }

        int rmIndex = length - n;

        int count = 0;
        while (count < rmIndex - 1) {
            head = head->next;
            count++;
        }

        head->next = head->next->next;

        return curr;
    }

    int getLength(ListNode *p) {
        int n = 0;
        while (p != NULL) {
            p = p->next;
            n++;
        }
        return n;
    }

    void print_list(ListNode *p) {
        while (p != NULL) {
            printf("val = %d\n", p->val);
            p = p->next;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(5);
    solution->print_list(p);
    printf("--\n");
    solution->print_list(solution->removeNthFromEnd(p, 2));
//    printf("%d\n", solution)
    return 0;
}