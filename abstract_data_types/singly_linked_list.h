#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

//Add a New ListNode
ListNode* singly_linked_list_add(ListNode* head, int val);

//Remove a ListNode
ListNode* singly_linked_list_remove(ListNode* head, ListNode* node);

//Search 
ListNode* singly_linked_list_search(ListNode* head, int val);

//Traverse
void singly_linked_list_traverse(ListNode* head);

//Cycle
void singly_linked_list_cycle(ListNode* head, ListNode* node);

#endif
