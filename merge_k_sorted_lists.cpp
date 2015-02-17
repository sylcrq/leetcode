#include <vector>
#include "singly_linked_list.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* mergeTwoLists_ii(ListNode* a, ListNode* b);

ListNode *mergeKLists(vector<ListNode *> &lists) 
{
    if(lists.empty())
        return NULL;

    int size = lists.size();

#if 0
    // 假设K个链表的长度都为N
    // 最差情况的时间复杂度: O(N*K^2)
    ListNode* head = lists[0];

    for(int i=1; i<size; i++)
        head = mergeTwoLists_ii(head, lists[i]);

    return head;
#else
    // 最差情况的时间复杂度: O(N*K*logK)
    while(size > 1)
    {
        int start = 0;
        int n = 0;

        while(start < (size-1))
        {
            lists[n] = mergeTwoLists_ii(lists[start], lists[start+1]);

            start += 2;
            n++;
        }

        if(start == (size-1))
        {
            lists[n] = lists[start];
            n++;
        }

        size = n;
    }

    return lists[0];
#endif
}

ListNode* mergeTwoLists_ii(ListNode* a, ListNode* b)
{
    if(!a) return b;
    if(!b) return a;

    // merge list b to list a
    ListNode* head = a;
    ListNode* prev = a;

    while(a != NULL && b != NULL)
    {
        if(a->val <= b->val)
        {
            prev = a;
            a = a->next;
        }
        else
        {
            ListNode* tmp = b->next;

            if(a == head)
                head = b;
            else
                prev->next = b;

            b->next = a;
            prev = b;
            b = tmp;
        }
    }

    if(b != NULL)
    {
        prev->next = b;
    }

    return head;
}
