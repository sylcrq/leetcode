#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void reorderList(ListNode *head) 
{
    if(!head) return;

    ListNode* fast = head;
    ListNode* slow = head;
    while(1)
    {
        fast = fast->next;
        if(!fast) break;

        fast = fast->next;
        if(!fast) break;

        slow = slow->next;
    }

    // 1. divide into two lists
    ListNode* list_1 = head;
    ListNode* list_2 = slow->next;
    slow->next = NULL;

#if 0
    int size = 0;
    ListNode* node = head;
    while(node != NULL)
    {
        size++;
        node = node->next;
    }

    int n = ((size % 2) == 0) ? ((size/2) - 1) : (size / 2);
    node = head;
    while(n > 0)
    {
        n--;
        node = node->next;
    }

    // 1. divide into two lists
    ListNode* list_1 = head;
    ListNode* list_2 = node->next;
    node->next = NULL;
#endif

    if(!list_2) return;

    // 2. reverse list_2
    ListNode* prev = list_2;
    ListNode* curr = list_2->next;
    while(curr != NULL)
    {
        prev->next = curr->next;
        curr->next = list_2;
        list_2 = curr;

        curr = prev->next;
    }
    
#if 0
    ListNode* list_2_tail = list_2;
    int list_2_size = 1;
    while(list_2_tail->next != NULL)
    {
        list_2_size++;
        list_2_tail = list_2_tail->next;
    }

    while(list_2_size > 1)
    {
        list_2_size--;

        ListNode* tmp = list_2->next;

        list_2->next = list_2_tail->next;
        list_2_tail->next = list_2;
        list_2 = tmp;
    }
#endif

    // 3. merge list_1 & list_2
    while(list_1 != NULL && list_2 != NULL)
    {
        ListNode* tmp = list_2;
        list_2 = list_2->next;

        tmp->next = list_1->next;
        list_1->next = tmp;

        list_1 = list_1->next->next;
    }
}

