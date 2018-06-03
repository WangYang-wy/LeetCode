//
// Created by 王阳 on 2018/6/3.
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
public:
    ListNode *detectCycle(ListNode *head) {
        std::set<ListNode *> node_set;
        while (head) {
            if (node_set.find(head) != node_set.end()) { // 如果发现存在，那么直接返回该结点。
                return head;
            }
            node_set.insert(head);
            head = head->next;
        }
        return NULL;
    }
};
