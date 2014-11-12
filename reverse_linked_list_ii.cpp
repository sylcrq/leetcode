#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Reverse a linked list from position m to n. 
// Do it in-place and in one-pass.
ListNode *reverseBetween(ListNode *head, int m, int n) 
{
    if(!head) return NULL;

    ListNode* prev = head;
    ListNode* start = head;

    int count = n - m;

    // 找到开始reverse的链表节点"start"和它之前的那个节点"prev"
    while(m > 1)
    {
        prev = start;
        start = start->next;

        m--;
    }

    bool reverse_from_head = false;

    if(start == head)
        reverse_from_head = true;

    // 每次将"start"之后那个节点移动到"prev"之后
    while(count > 0)
    {
        ListNode* tmp = start->next;

        if(reverse_from_head)
        {
            // 处理从头节点开始reverse的情况
            start->next = tmp->next;
            tmp->next = head;
            head = tmp;
        }
        else
        {
            start->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        
        count--;
    }

    return head;
}

