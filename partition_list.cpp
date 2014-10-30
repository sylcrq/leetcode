#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *partition(ListNode *head, int x) 
{
    if(!head) return NULL;

    // 找到第一个大于等于x的node
    ListNode* target = head;
    ListNode* prev = head;
    while(target != NULL && target->val < x)
    {
        prev = target;
        target = target->next;
    }

    if(!target)
        return head;

    // 从第一个大于等于x的node开始遍历
    ListNode* node = target;
    while(node->next != NULL)
    {
        if(node->next->val < x)
        {
            ListNode* tmp = node->next;
            // delete
            node->next = node->next->next;

            // insert
            if(target == head)
            {
                // head
                tmp->next = head;
                head = tmp;
            }
            else
            {
                // after prev
                tmp->next = prev->next;
                prev->next = tmp;
            }

            // update prev
            prev = tmp;
        }
        else
        {
            node = node->next;
        }
    }

    return head;
}

