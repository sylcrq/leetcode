#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include <iostream>

ListNode *insertionSortList(ListNode *head);


TEST(InsertionSortListTestCase, Normal)
{
    ListNode* head = NULL;
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 11);
    head = singly_linked_list_add(head, 8);
    head = singly_linked_list_add(head, 7);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 9);
    head = singly_linked_list_add(head, 4);

    singly_linked_list_traverse(head);

    head = insertionSortList(head);

    std::cout << "after insertion sort:" << std::endl;
    singly_linked_list_traverse(head);
}
