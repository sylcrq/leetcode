#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *detectCycle(ListNode *head) 
{
    if(!head) return NULL;

    ListNode* fast = head;  // 一次走二步
    ListNode* slow = head;  // 一次走一步

    bool has_cycle = false;

    // 检测链表中是否有环
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            has_cycle = true;
            break;
        }
    }

    ListNode* result = NULL;

    if(has_cycle)
    {
        result = head;

        while(result != slow)
        {
            result = result->next;
            slow = slow->next;
        }
    }

    return result;
}

