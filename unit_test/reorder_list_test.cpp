#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include <iostream>

void reorderList(ListNode *head);

TEST(ReorderListTestCase, EvenSize)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);
    head = singly_linked_list_add(head, 6);
    head = singly_linked_list_add(head, 7);
    head = singly_linked_list_add(head, 8);

    singly_linked_list_traverse(head);

    reorderList(head);

    std::cout << "after reorder:" << std::endl;
    singly_linked_list_traverse(head);
}

TEST(ReorderListTestCase, OddSize)
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

    reorderList(head);

    std::cout << "after reorder:" << std::endl;
    singly_linked_list_traverse(head);
}

TEST(ReorderListTestCase, OneNode)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 1);

    singly_linked_list_traverse(head);

    reorderList(head);

    std::cout << "after reorder:" << std::endl;
    singly_linked_list_traverse(head);
}

