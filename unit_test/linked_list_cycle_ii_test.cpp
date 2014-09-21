#include "gtest/gtest.h"
#include "singly_linked_list.h"

ListNode *detectCycle(ListNode *head);

TEST(LinkedListCycleIITestCase, Normal)
{
    ListNode* head = NULL;

    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);

    singly_linked_list_traverse(head);

    EXPECT_EQ(NULL, detectCycle(head));

    head = singly_linked_list_add(head, 6);
    ListNode* node = singly_linked_list_search(head, 3);
    singly_linked_list_cycle(head, node);

    EXPECT_EQ(node, detectCycle(head));
}
