#include "gtest/gtest.h"
#include "binary_tree.h"
#include "singly_linked_list.h"

TreeNode *sortedListToBST(ListNode *head);

TEST(ConvertSortedListtoBinarySearchTreeTestCase, Normal)
{
    ListNode* head = NULL;
    head = singly_linked_list_add(head, 1);
    head = singly_linked_list_add(head, 2);
    head = singly_linked_list_add(head, 3);
    head = singly_linked_list_add(head, 4);
    head = singly_linked_list_add(head, 5);
    head = singly_linked_list_add(head, 6);
    head = singly_linked_list_add(head, 7);

    TreeNode* root = sortedListToBST(head);

    binary_tree_print(root);
}
