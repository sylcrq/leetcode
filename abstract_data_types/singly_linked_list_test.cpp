#include "gtest/gtest.h"
#include "singly_linked_list.h"

TEST(SinglyLinkedListTestCase, Normal)
{
    //TODO: 
    ListNode* head = NULL;
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);

    ListNode* node = singly_linked_list_search(head, 3);
    head = singly_linked_list_remove(head, node);

    head = singly_linked_list_remove(head, head);

    singly_linked_list_traverse(head);

    //TODO: release memory
}

