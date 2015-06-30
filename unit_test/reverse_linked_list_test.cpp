#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include <vector>

using namespace std;

ListNode* reverseList(ListNode* head);

TEST(ReverseLinkedListTestCase, Normal) {
    int test_data[] = {1,2,3,4,5,6};
    vector<int> data(test_data, test_data + sizeof(test_data)/sizeof(int));

    ListNode* head = create_singly_linked_list(data);
    singly_linked_list_traverse(head);

    ListNode* reverse = reverseList(head);
    singly_linked_list_traverse(reverse);
}

