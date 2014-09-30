#include "gtest/gtest.h"
#include "singly_linked_list.h"

ListNode *removeNthFromEnd(ListNode *head, int n);
ListNode *removeNthFromEnd_ii(ListNode *head, int n);

TEST(RemoveNthNodeFromEndOfListTestCase, Normal)
{
    ListNode* head = NULL;
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);

    singly_linked_list_traverse(head);
    
    head = removeNthFromEnd_ii(head, 2);
    
    singly_linked_list_traverse(head);

    head = removeNthFromEnd_ii(head, 4);

    singly_linked_list_traverse(head);
}


