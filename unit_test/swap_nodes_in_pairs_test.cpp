#include "gtest/gtest.h"
#include "singly_linked_list.h"

#include <iostream>

ListNode *swapPairs(ListNode *head);

TEST(SwapNodesInPairsTestCase, Normal)
{
    ListNode* list = NULL;

    list = singly_linked_list_add(list, 1);
    list = singly_linked_list_add(list, 2);
    list = singly_linked_list_add(list, 3);
    list = singly_linked_list_add(list, 4);
    list = singly_linked_list_add(list, 5);

    std::cout << "before swap:" << std::endl;
    singly_linked_list_traverse(list);

    ListNode* new_list = swapPairs(list);

    std::cout << "after swap:" << std::endl;
    singly_linked_list_traverse(new_list);
}
