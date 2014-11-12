#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include <iostream>

ListNode *reverseBetween(ListNode *head, int m, int n);

TEST(ReverseLinkedListIITestCase, Normal)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);
    head = singly_linked_list_add(head, 6);
    head = singly_linked_list_add(head, 7);

    singly_linked_list_traverse(head);

    head = reverseBetween(head, 3, 6);

    std::cout << "after reverse:" << std::endl;
    singly_linked_list_traverse(head);
}
