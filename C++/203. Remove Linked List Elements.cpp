//
// Created by 王阳 on 2018/4/3.
//
/**
 * Remove all elements from a linked list of integers that have value val.
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 */

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
    ListNode *removeElements(ListNode *head, int val) {
        if (NULL == head) {
            return NULL;
        }

        ListNode *res = head;

        while (head != NULL) {
            if (val == head->val && head->next != NULL) { // 头结点为该值，并且不是尾结点。
                printf("头结点为该值：%d。\n", head->val);
                ListNode *tmp = head;
                head = head->next;
                res = res->next;
                delete tmp;
                continue;
            } else if (val == head->val && head->next == NULL) { // 头结点为该值，并且是尾结点。
                printf("当前结点为该值，并且是尾结点。\n");
                return NULL;
            } else { // 现在的链表，头结点不是该值，并且链表非空。
                if (head->next == NULL) { // 如果链表只有一个元素，那么直接返回。
                    return res;
                }

                while (head->next != NULL) { // 链表元素多于1个。
                    if (head->next->next != NULL && val == head->next->val) {
                        ListNode *tmp = head->next;
                        head->next = head->next->next;
                        delete tmp;
                        continue;
                    }

                    if (head->next->next == NULL && val == head->next->val) {
                        delete head->next;
                        head->next = NULL;
                        return res;
                    }

                    head = head->next;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *tmp = new ListNode(1);
    tmp->next = new ListNode(2);
    tmp->next->next = new ListNode(2);
    tmp->next->next->next = new ListNode(1);
//    tmp->next->next->next->next = new ListNode(4);
//    tmp->next->next->next->next->next = new ListNode(5);
//    tmp->next->next->next->next->next->next = new ListNode(6);
    print_list(tmp);
    ListNode *res = solution->removeElements(tmp, 2);
    print_list(res);
//    printf("%d\n", tmp);
    return 0;
}