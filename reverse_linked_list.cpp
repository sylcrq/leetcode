#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseList(ListNode* head) {
    if(!head) return NULL;

    ListNode* tail = head;
    int count = 0;

    while(tail->next != NULL) {
        tail = tail->next;
        count++;
    }

    while(count > 0) {
        ListNode* tmp = head;
        head = head->next;

        tmp->next = tail->next;
        tail->next = tmp;
        count--;
    }

    return head;
}
