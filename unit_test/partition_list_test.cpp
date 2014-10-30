#include "gtest/gtest.h"
#include "singly_linked_list.h"

ListNode *partition(ListNode *head, int x);


TEST(PartitionListTestCase, Normal)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 1);    
    head = singly_linked_list_add(head, 4);    
    head = singly_linked_list_add(head, 3);    
    head = singly_linked_list_add(head, 2);    
    head = singly_linked_list_add(head, 5);    
    head = singly_linked_list_add(head, 2);

    singly_linked_list_traverse(head);

    head = partition(head, 3);
    singly_linked_list_traverse(head);
}

TEST(PartitionListTestCase, AllLessThanTarget)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 1);

    singly_linked_list_traverse(head);

    head = partition(head, 2);
    singly_linked_list_traverse(head);
}

TEST(PartitionListTestCase, Normal2)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 0);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 0);
    head = singly_linked_list_add(head, 3);

    singly_linked_list_traverse(head);

    head = partition(head, 4);
    singly_linked_list_traverse(head);
}

TEST(PartitionListTestCase, AllGreaterThanTarget)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);

    singly_linked_list_traverse(head);

    head = partition(head, 2);
    singly_linked_list_traverse(head);
}

TEST(PartitionListTestCase, EqualToTargetAtListHead)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);

    singly_linked_list_traverse(head);

    head = partition(head, 3);
    singly_linked_list_traverse(head);
}

