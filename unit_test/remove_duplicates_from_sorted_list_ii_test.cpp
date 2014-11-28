#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include <iostream>

ListNode *deleteDuplicates_ii(ListNode *head);

TEST(RemoveDuplicatesFromSortedListIITestCase, Normal)
{
    ListNode* head = NULL;
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);

    singly_linked_list_traverse(head);

    head = deleteDuplicates_ii(head);

    std::cout << "after:" << std::endl;
    singly_linked_list_traverse(head);
}
