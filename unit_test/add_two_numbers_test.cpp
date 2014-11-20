#include "gtest/gtest.h"
#include "singly_linked_list.h"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

TEST(AddTwoNumbersTestCase, Normal)
{
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    l1 = singly_linked_list_add(l1, 2);
    l1 = singly_linked_list_add(l1, 4);
    l1 = singly_linked_list_add(l1, 3);

    l2 = singly_linked_list_add(l2, 5);
    l2 = singly_linked_list_add(l2, 6);
    l2 = singly_linked_list_add(l2, 7);
    l2 = singly_linked_list_add(l2, 9);

    singly_linked_list_traverse(l1);
    singly_linked_list_traverse(l2);

    ListNode* head = addTwoNumbers(l1, l2);
    singly_linked_list_traverse(head);
}
