#include "gtest/gtest.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* AddListNode(ListNode* head, ListNode* node);
void PrintList(ListNode* head);

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

TEST(MergeTwoSortedListsTestCase, ListIsNull)
{
    ListNode* List_A = new ListNode(2);
    ListNode* List_B = new ListNode(1);

    AddListNode(List_A, new ListNode(4));
    AddListNode(List_A, new ListNode(6));
    AddListNode(List_A, new ListNode(10));

    PrintList(List_A);
    PrintList(List_B);

    EXPECT_EQ(List_A, mergeTwoLists(List_A, NULL));
    EXPECT_EQ(List_B, mergeTwoLists(NULL, List_B));
    EXPECT_EQ(NULL, mergeTwoLists(NULL, NULL));
}

TEST(MergeTwoSortedListsTestCase, Normal)
{
    ListNode* List_A = new ListNode(2);
    ListNode* List_B = new ListNode(1);

    AddListNode(List_A, new ListNode(4));
    AddListNode(List_A, new ListNode(6));
    AddListNode(List_A, new ListNode(10));

    AddListNode(List_B, new ListNode(7));

    ListNode* ptr = mergeTwoLists(List_A, List_B);
    PrintList(ptr);
}
