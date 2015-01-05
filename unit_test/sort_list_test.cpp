#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include <iostream>

ListNode *sortList(ListNode *head); 
int merge_sort_list_in_place(ListNode* list_1, int size_1, 
                             ListNode* list_2, int size_2, 
                             ListNode** head, 
                             ListNode** tail);

TEST(SortListTestCase, MergeSortLinkedList)
{
    ListNode* head_1 = NULL;
    ListNode* head_2 = NULL;

    head_1 = singly_linked_list_add(head_1, 1);
    head_1 = singly_linked_list_add(head_1, 3);
    head_1 = singly_linked_list_add(head_1, 5);
    head_1 = singly_linked_list_add(head_1, 7);
    head_1 = singly_linked_list_add(head_1, 9);
    head_1 = singly_linked_list_add(head_1, 11);
    head_1 = singly_linked_list_add(head_1, 12);

    head_2 = singly_linked_list_add(head_2, 2);
    head_2 = singly_linked_list_add(head_2, 4);
    head_2 = singly_linked_list_add(head_2, 6);
    head_2 = singly_linked_list_add(head_2, 8);
    head_2 = singly_linked_list_add(head_2, 10);
    head_2 = singly_linked_list_add(head_2, 12);

    singly_linked_list_traverse(head_1);
    singly_linked_list_traverse(head_2);

    ListNode* head = NULL;
    ListNode* tail = NULL;
    merge_sort_list_in_place(head_1, 7, head_2, 6, &head, &tail);

    std::cout << "after merge sort:" << std::endl;
    singly_linked_list_traverse(head);
    std::cout << "head=" << head->val << ", tail=" << tail->val << std::endl;
}

TEST(SortListTestCase, Normal)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 9);
    head = singly_linked_list_add(head, 8);
    head = singly_linked_list_add(head, 7);
    head = singly_linked_list_add(head, 6);
    head = singly_linked_list_add(head, 5);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 10);

    singly_linked_list_traverse(head);

    head = sortList(head);

    std::cout << "after sort:" << std::endl;
    singly_linked_list_traverse(head);
}

