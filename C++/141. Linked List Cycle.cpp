//
// Created by 王阳 on 2018/3/27.
//

/**
 * Definition for singly-linked list.
 */

/*
 * 最常见的想法是遍历linked list，同时用个set进行记录遍历过的节点，如果遍历linked list
 * 时发现当前节点已经在set中出现过了。那就说明成环了。set将使用O(N)的空间复杂度。
 * 但是，题目要求不用extra space。所以可以考虑两个指针first, second在linked list上遍历，
 * 一个跑得快，一个跑得慢。如果linked list成环，那么慢指针终将被快指针追上。
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle_TLE(ListNode *head) {
        while (head != NULL) {
            ListNode *tmp = head->next;
            while (tmp != NULL) {
                if (head == tmp) {
                    return true;
                }
                tmp = tmp->next;
            }
            head = head->next;
        }
        return false;
    }

    /*
     * 所以可以考虑两个指针first, second在linked list上遍历，
     * 一个跑得快，一个跑得慢。如果linked list成环，那么慢指针终将被快指针追上。
     */
    bool hasCycle(ListNode *head) {
        ListNode *first = head;
        ListNode *second = head;
        while (first != NULL && second != NULL && second->next != NULL) {
            first = first->next;
            second = second->next->next;
            if (first == second) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *p = new ListNode(1);
    p->next = new ListNode(1);
    // p->next->next = p;
    p->next->next = new ListNode(2);
    printf("%d\n", solution->hasCycle(p));
    return 0;
}