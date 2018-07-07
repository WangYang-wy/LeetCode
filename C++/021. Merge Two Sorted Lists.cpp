//
// Created by 王阳 on 2018/3/30.
//

#include "header.h"

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *curr;

        if (NULL == l1 && NULL == l2) {
            return NULL;
        } else if (NULL == l1 && NULL != l2) {
            curr = l2;
        } else if (NULL != l1 && NULL == l2) {
            curr = l1;
        } else {
            if (l1->val <= l2->val) {
                curr = l1;
                curr->next = mergeTwoLists(l1->next, l2);
            } else {
                curr = l2;
                curr->next = mergeTwoLists(l1, l2->next);
            }
        }

        return curr;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(4);

    ListNode *q = new ListNode(1);
    q->next = new ListNode(3);
    q->next->next = new ListNode(4);

    ListNode *res = solution->mergeTwoLists(p, q);

    while (res != NULL) {
        printf("val = %d\n", res->val);
        res = res->next;
    }
    return 0;
}