#include "gtest/gtest.h"
#include "random_linked_list.h"

using namespace std;

TEST(RandomLinkedListTestCase, Normal)
{
    int num[5] = {1, 2, 3, 4, 5};
    vector<int> value(num, num+5);

    RandomListNode* head = init_random_linked_list(value);
    print_random_linked_list(head);
}
