#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse_linked_list(ListNode* head, ListNode* tail);

// 时间复杂度 O(k*N)
ListNode *reverseKGroup(ListNode *head, int k) 
{
    if(!head || k <= 0)
        return head;

    ListNode* start = head;
    ListNode* end = start;
    ListNode* prev = start;

    while(start != NULL)
    {
        int count = k;
        while(count > 0 && end != NULL)
        {
            count--;
            end = end->next;
        }

        if(count > 0)
            break;

        ListNode* node = reverse_linked_list(start, end);
        if(start == head)
        {
            head = node;
        }
        else
        {
            prev->next = node;
        }

        //update "prev" & "start" & "end"
        prev = start;
        start = end;
        end = start;
    }

    return head;
}

// reverse linked list [head, tail)
ListNode* reverse_linked_list(ListNode* head, ListNode* tail)
{
    //if(head == tail)
    //    return head;

    ListNode* node = head;

    while(node->next != tail)
    {
        ListNode* tmp = node->next;

        node->next = node->next->next;
        tmp->next = head;
        head = tmp;

        // "node" DO NOT move 
    }

    return head;
}
