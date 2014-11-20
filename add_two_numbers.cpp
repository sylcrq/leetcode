#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
{
    if(!l1) return l2;
    if(!l2) return l1;

    ListNode* p1 = l1;
    ListNode* p2 = l2;

    ListNode* head = NULL;
    ListNode* p = head;

    int flag = 0;

    while(p1 || p2)
    {
        int num1 = (p1 != NULL) ? p1->val : 0;
        int num2 = (p2 != NULL) ? p2->val : 0;

        int sum = (num1 + num2 + flag) % 10;
        flag = (num1 + num2 + flag) / 10;

        if(head == NULL)
        {
            head = new ListNode(sum);
            p = head;
        }
        else
        {
            p->next = new ListNode(sum);
            p = p->next;
        }

        if(p1 != NULL)
            p1 = p1->next;
        if(p2 != NULL)
            p2 = p2->next;
    }

    //p1 = (p1 != NULL) ? p1 : p2;
    //
    //while(p1)
    //{
    //    int sum = (p1->val + flag) % 10;
    //    flag = (p1->val + flag) / 10;
    //
    //    p->next = new ListNode(sum);
    //    p = p->next;
    //
    //    p1 = p1->next;
    //}

    if(flag)
    {
        p->next = new ListNode(flag);
    }

    return head;
}

