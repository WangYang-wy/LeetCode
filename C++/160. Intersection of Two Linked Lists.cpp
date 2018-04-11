//
// Created by 王阳 on 2018/4/11.
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
 /**
  * 参考博客：https://blog.csdn.net/sunao2002002/article/details/45727149
  * 解法：如果结点相同，即地址相同，指向同一个结点，即后续结点也相同。
  */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL && headB == NULL) {
            return NULL;
        }
        int a_length = getLength(headA);
        int b_length = getLength(headB);

        int n = a_length - b_length;
        for (int i = 0; i < abs(n); i++) {
            if (n > 0) {
                headA = headA->next;
            } else {
                headB = headB->next;
            }
        }

        // 现在两个链表长度相同。
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }

    /**
     * 获取链表的长度。
     * @param p 链表。
     * @return 长度。
     */
    int getLength(ListNode *p) {
        int i = 0;
        while (p) {
            i++;
            p = p->next;
        }
        return i;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}