#include "random_linked_list.h"
#include "gtest/gtest.h"

using namespace std;

RandomListNode *copyRandomList(RandomListNode *head);
RandomListNode* copyRandomList_ii(RandomListNode* head);

TEST(CopyListWithRandomPointerTestCase, Normal)
{
    int num[5] = {1, 2, 3, 4, 5};
    vector<int> value(num, num+5);

    RandomListNode* head = init_random_linked_list(value);
    print_random_linked_list(head);

    RandomListNode* copy = copyRandomList_ii(head);
    print_random_linked_list(copy);
}
