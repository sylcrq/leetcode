#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *swapPairs(ListNode *head)
{
    ListNode* prev = head;
    ListNode* curr = head;

    while(curr && curr->next)
    {
        if(prev == curr)
        {
            prev = curr->next;
            curr->next = curr->next->next;
            prev->next = curr;

            head = prev;  // update head
        }
        else
        {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
        }
    
        prev = curr;
        curr = curr->next;
    }

    return head;
}

