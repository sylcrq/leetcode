#include "gtest/gtest.h"
#include "singly_linked_list.h"


bool hasCycle(ListNode *head);

TEST(LinkedListCycleTestCase, LinkedListIsNull)
{
    ListNode* head = NULL;

    EXPECT_FALSE( hasCycle(head) );
}

TEST(LinkedListCycleTestCase, LinkedListNoCycle)
{
    ListNode* head = NULL;
    head = singly_linked_list_add(head, 1);
    singly_linked_list_traverse(head);

    EXPECT_FALSE( hasCycle(head) );  // 1

    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    singly_linked_list_traverse(head);

    EXPECT_FALSE( hasCycle(head) );  // 1 -> 2 -> 3

    //TODO: release memory
}

TEST(LinkedListCycleTestCase, LinkedListHasCycle)
{
    ListNode* head = NULL;
    head = singly_linked_list_add(head, 1);
    singly_linked_list_cycle(head, head);
    
    EXPECT_TRUE( hasCycle(head) );

    //TODO: release memory

    ListNode* head2 = NULL;
    head2 = singly_linked_list_add(head2, 1);
    singly_linked_list_add(head2, 2);
    singly_linked_list_add(head2, 3);
    singly_linked_list_add(head2, 4);
    ListNode* node = singly_linked_list_search(head2, 2);
    singly_linked_list_cycle(head2, node);

    EXPECT_TRUE( hasCycle(head2) );

    //TODO: release memory
}
