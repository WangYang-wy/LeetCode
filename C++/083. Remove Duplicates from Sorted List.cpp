//
// Created by 王阳 on 2018/4/17.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *tmp = head;
        if (head == NULL || head->next == NULL) { // 如果没有结点或者只有一个结点。
            return head;
        }

        while (head->next) {
            if (head->val == head->next->val) { // 存在重复。
                ListNode *tmp = head->next->next;
                delete head->next;
                head->next = tmp;
            } else {
                head = head->next;
            }
        }
        return tmp;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}