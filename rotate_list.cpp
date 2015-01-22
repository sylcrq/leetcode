#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *rotateRight(ListNode *head, int k) 
{
    if(!head || k < 0)
        return head;

    int size = 1;
    ListNode* last = head;
    while(last->next != NULL)
    {
        size++;
        last = last->next;
    }

    // Note: k = k % size
    k = k % size;
    if(k == 0)
        return head;

    ListNode* ptr = head;
    int n = size - k - 1;

    while(n > 0)
    {
        n--;
        ptr = ptr->next;
    }

    ListNode* tmp = ptr->next;
    ptr->next = last->next;
    last->next = head;
    head = tmp;

    return head;
}

