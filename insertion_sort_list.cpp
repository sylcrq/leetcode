#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *insertionSortList(ListNode *head) 
{
    if(!head) return NULL;

    // 分为两个链表: head & to_sort_list
    ListNode* to_sort_list = head->next;
    head->next = NULL;

    while(to_sort_list != NULL)
    {
        ListNode* node = to_sort_list;
        to_sort_list = to_sort_list->next;
        //node->next = NULL;

        // insertion sort
        ListNode* ptr = head;
        ListNode* prev = head;
        while(ptr != NULL)
        {
            if(node->val < ptr->val)
                break;

            prev = ptr;
            ptr = ptr->next;
        }

        if(ptr == head)
        {
            node->next = head;
            head = node;
        }
        else
        {
            node->next = prev->next;
            prev->next = node;
        }
    }

    return head;
}

