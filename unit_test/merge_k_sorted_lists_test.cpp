#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include <vector>

using namespace std;

ListNode* mergeTwoLists_ii(ListNode* a, ListNode* b);
ListNode *mergeKLists(vector<ListNode *> &lists); 

TEST(MergeKSortedListsTestCase, MergeTwoLists)
{
    int list_1[3] = {1, 3, 5};
    int list_2[4] = {2, 4, 6, 8};

    vector<int> list_1_(list_1, list_1+3);
    vector<int> list_2_(list_2, list_2+4);

    ListNode* l1 = create_singly_linked_list(list_1_);
    ListNode* l2 = create_singly_linked_list(list_2_);

    ListNode* merged = mergeTwoLists_ii(l1, l2);

    singly_linked_list_traverse(merged);
}

TEST(MergeKSortedListsTestCase, Normal)
{
    int list_1[3] = {1,8,15};
    int list_2[4] = {2,9,16,22};
    int list_3[6] = {3,10,17,23,28,31};
    int list_4[4] = {4,11,18,24};
    int list_5[8] = {5,12,19,25,29,32,33,34};
    int list_6[5] = {6,13,20,26,30};
    int list_7[4] = {7,14,21,27};

    vector<int> list_1_(list_1, list_1+3);
    vector<int> list_2_(list_2, list_2+4);
    vector<int> list_3_(list_3, list_3+6);
    vector<int> list_4_(list_4, list_4+4);
    vector<int> list_5_(list_5, list_5+8);
    vector<int> list_6_(list_6, list_6+5);
    vector<int> list_7_(list_7, list_7+4);

    ListNode* l1 = create_singly_linked_list(list_1_);
    ListNode* l2 = create_singly_linked_list(list_2_);
    ListNode* l3 = create_singly_linked_list(list_3_);
    ListNode* l4 = create_singly_linked_list(list_4_);
    ListNode* l5 = create_singly_linked_list(list_5_);
    ListNode* l6 = create_singly_linked_list(list_6_);
    ListNode* l7 = create_singly_linked_list(list_7_);

    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    lists.push_back(l4);
    lists.push_back(l5);
    lists.push_back(l6);
    lists.push_back(l7);

    ListNode* merged = mergeKLists(lists);

    singly_linked_list_traverse(merged);
}

