#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode* node = head;
    
    while(node != NULL && node->next != NULL)
    {
        if(node->val == node->next->val)
        {
            // delete
            node->next = node->next->next;
        }
        else
        {
            node = node->next;
        }
    }

    return head;    
}
