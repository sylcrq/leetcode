#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool hasCycle(ListNode *head)
{
    if(!head) return false;

    bool ret = false;

    ListNode* fast = head;
    ListNode* slow = head;

    while(fast->next && slow->next && fast->next->next)
    {
        fast = fast->next->next;  //two steps
        slow = slow->next;        //one step

        if(fast == slow)
        {
            ret = true;
            break;
        }
    }

    return ret;
}
