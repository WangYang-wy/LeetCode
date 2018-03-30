//
// Created by 王阳 on 2018/3/30.
//

#ifndef LEETCODE_HEADER_H
#define LEETCODE_HEADER_H

#include <iostream>

/**
 * 链表节点。
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 树的节点。
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 打印一个链表的所有元素。
 * @param p 链表。
 */
void print_list(ListNode *p) {
    while (p != NULL) {
        printf("val = %d\n", p->val);
        p = p->next;
    }
}

#endif //LEETCODE_HEADER_H
