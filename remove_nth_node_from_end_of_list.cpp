#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *removeNthFromEnd(ListNode *head, int n) 
{
    if(!head || n<=0)
        return head;

    ListNode* node_to_remove = head;
    ListNode* prev_node_to_remove = head;
    ListNode* n_steps = head;

    while(n_steps != NULL && n > 1)
    {
        n_steps = n_steps->next;
        n--;
    }

    if(n_steps != NULL)
    {
        while(n_steps->next != NULL)
        {
            n_steps = n_steps->next;
            prev_node_to_remove = node_to_remove;
            node_to_remove = node_to_remove->next;
        }

        // delete
        if(node_to_remove == head)
            head = node_to_remove->next;
        else
            prev_node_to_remove->next = node_to_remove->next;
    }

    return head;
}

ListNode *removeNthFromEnd_ii(ListNode *head, int n)
{
    if(!head || n<=0)
        return head;

    ListNode* prev_node_to_remove = head;
    ListNode* n_steps = head;

    while(n_steps != NULL && n > 0)
    {
        n_steps = n_steps->next;
        n--;
    }

    if(!n_steps && n == 0)
    {
        // delete
        head = head->next;
    }
    else if(n_steps != NULL && n == 0)
    {
        while(n_steps->next != NULL)
        {
            n_steps = n_steps->next;
            prev_node_to_remove = prev_node_to_remove->next;
        }

        // delete
        prev_node_to_remove->next = prev_node_to_remove->next->next;
    }

    return head;
}

