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
    void deleteNode(ListNode *node) {
        if (!node || !node->next)
            return;
        node->val = node->next->val;
        delete node->next;
        node->next = node->next->next;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}