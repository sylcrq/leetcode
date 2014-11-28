#include "singly_linked_list.h"

ListNode *deleteDuplicates_ii(ListNode *head) 
{
    if(!head) return NULL;

    ListNode* node = head;
    ListNode* prev = head;
    while(node != NULL)
    {
        bool duplicate = false;

        while(node->next != NULL && node->val == node->next->val)
        {
            duplicate = true;

            ListNode* tmp = node->next;
            node->next = node->next->next;
            delete tmp;
        }

        if(duplicate)
        {
            if(node == head)
            {
                head = node->next;
                prev = node->next;
            }
            else
            {
                prev->next = node->next;
            }

            ListNode* tmp = node;
            node = node->next;
            delete tmp;
        }
        else
        {
            prev = node;
            node = node->next;
        }
    }

    return head;
}

