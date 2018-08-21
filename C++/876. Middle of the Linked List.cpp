//
// Created by 王阳 on 2018/8/20.
//

#include "header.h"

class Solution {
private:
    int getLength(ListNode *head) {
        int i = 0;
        while (head) {
            i++;
            head = head->next;
        }
        return i;
    }

public:
    ListNode *middleNode(ListNode *head) {
        int n = this->getLength(head);
        if (1 == n % 2) {
            int i = 0;
            int index = n / 2;
            while (i < index) {
                head = head->next;
                i++;
            }
            return head;
        } else {
            int i = 0;
            int index = n / 2;
            while (i < index) {
                head = head->next;
                i++;
            }
            return head;
        }
    }
};

int main() {
    return 0;
}