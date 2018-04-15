//
// Created by 王阳 on 2018/4/15.
//

#include "header.h"


/**
 * 参考博客：https://blog.csdn.net/sunao2002002/article/details/46918645
 *
 */
class Solution {
public:
    bool isPalindrome_tle(ListNode *head) {
        int n = getLength(head);
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (getIndex(head, i) != getIndex(head, j)) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    /**
     * 反转链表法，将链表后半段原地翻转，再将前半段、后半段依次比较，
     * 判断是否相等，时间复杂度O（n），空间复杂度为O（1）满足题目要求。
     * @param head
     * @return
     */
    bool isPalindrome(ListNode *head) {
        if (NULL == head || NULL == head->next) { // 链表为空或者只有一个结点，是回文的。
            return true;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // 两个指针，一个增加一步，一个增加两步。
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) { // 链表的元素为奇数。
            slow->next = reverseList(slow->next);
            slow = slow->next;
            while (slow) {
                if (head->val != slow->val) {
                    return false;
                }
                slow = slow->next;
                head = head->next;
            }
            return true;
        } else {// 链表的元素为偶数。
            slow = reverseList(slow);

            while (slow) {
                if (head->val != slow->val) {
                    return false;
                }
                slow = slow->next;
                head = head->next;
            }
            return true;
        }
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *temp = head;
        if (head == NULL || head->next == NULL) { // 只有一个结点或者空，不需要翻转。
            return head;
        }

        int n = getLength(head);
        ListNode *last;
        while (temp->next) {
            temp = temp->next;
        }
        last = temp;

        ListNode *res = last;
        last->next = head;
        head = head->next;
        last->next->next = NULL;
        for (int i = 1; i < n - 1; i++) {
            ListNode *tmp = last->next;
            last->next = head;
            head = head->next;
            last->next->next = tmp;
        }
        return res;
    }

    int getLength(ListNode *head) {
        int res = 0;
        while (head) {
            head = head->next;
            res++;
        }
        return res;
    }

    int getIndex(ListNode *head, int i) {
        int res = 0;
        while (res < i) {
            head = head->next;
            res++;
        }
        std::cout << "第" << i << "个结点的取值为：" + head->val << "." << std::endl;
        return head->val;
    }
};

int main() {
    Solution *solution = new Solution();
    return 0;
}