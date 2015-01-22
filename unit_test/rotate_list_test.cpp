#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include <iostream>

ListNode *rotateRight(ListNode *head, int k);

TEST(RotateListTestCase, Normal)
{
    ListNode* head = NULL;
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);

    singly_linked_list_traverse(head);
    head = rotateRight(head, 2);

    std::cout << "after rotate:" << std::endl;
    singly_linked_list_traverse(head);
}

TEST(RotateListTestCase, GreaterThanListSize)
{
    ListNode* head = NULL;
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);

    singly_linked_list_traverse(head);
    head = rotateRight(head, 8);

    std::cout << "after rotate:" << std::endl;
    singly_linked_list_traverse(head);
}
