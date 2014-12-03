#include "gtest/gtest.h"
#include "singly_linked_list.h"

ListNode *reverseKGroup(ListNode *head, int k);
ListNode* reverse_linked_list(ListNode* head, ListNode* tail);

TEST(ReverseNodesInKGroupTestCase, ReverseList)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);
    head = singly_linked_list_add(head, 6);

    singly_linked_list_traverse(head);

    ListNode* node = head;
    while(node != NULL)
    {
        if(node->val == 5)
            break;

        node = node->next;
    }

    head = reverse_linked_list(head, node);

    singly_linked_list_traverse(head);
}

TEST(ReverseNodesInKGroupTestCase, Normal)
{ 
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);

    singly_linked_list_traverse(head);

    head = reverseKGroup(head, 3);

    singly_linked_list_traverse(head);
}


