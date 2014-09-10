#include "gtest/gtest.h"
#include "singly_linked_list.h"

ListNode *deleteDuplicates(ListNode *head);

TEST(RemoveDuplicatesFromSortedListTestCase, Normal)
{
    ListNode* list = NULL;

    list = singly_linked_list_add(list, 1);
    list = singly_linked_list_add(list, 1);
    list = singly_linked_list_add(list, 2);
    list = singly_linked_list_add(list, 3);
    list = singly_linked_list_add(list, 4);
    list = singly_linked_list_add(list, 4);

    singly_linked_list_traverse(list);

    list = deleteDuplicates(list);

    singly_linked_list_traverse(list);
}
