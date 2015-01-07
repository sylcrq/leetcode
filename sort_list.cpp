#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* get_node_after_n_steps(ListNode* node, int step);
int merge_sort_list_in_place(ListNode* list_1, int size_1, 
                             ListNode* list_2, int size_2, 
                             ListNode** head, 
                             ListNode** tail);

/* 要求: 时间复杂度 O(N*logN), 空间复杂度 O(1) */

// 一种更简洁的解法
ListNode *sortList_ii(ListNode *head)
{
    int size = 0;

    ListNode* ptr = head;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        size++;
    }

    for(int step=1; step<size; step=step<<1)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;

        while(slow != NULL && fast != NULL)
        {
            int i = 0;
            while(i < step && fast != NULL)
            {
                fast = fast->next;
                i++;
            }

            int slow_size = 0;
            int fast_size = 0;

            // merge
            while(slow_size < step && fast_size < step && slow != NULL && fast != NULL)
            {
                if(slow->val < fast->val)
                {
                    prev = slow;
                    slow = slow->next;
                    slow_size++;
                }
                else
                {
                    ListNode* tmp = fast->next;

                    // if slow == prev == head, update head
                    if(slow == head && slow == prev)
                    {
                        fast->next = slow;
                        prev = fast;
                        head = fast;
                    }
                    else
                    {
                        fast->next = prev->next;
                        prev->next = fast;
                        prev = fast;
                    }

                    fast = tmp;
                    fast_size++;
                }
            }

            while(slow_size < step && slow != NULL)
            {
                prev = slow;
                slow = slow->next;
                slow_size++;
            }            

            while(fast_size < step && fast != NULL)
            {
                ListNode* tmp = fast->next;

                // if slow == prev == head, update head
                if(slow == head && slow == prev)
                {
                    fast->next = slow;
                    prev = fast;
                    head = fast;
                }
                else
                {
                    fast->next = prev->next;
                    prev->next = fast;
                    prev = fast;
                }

                fast = tmp;
                fast_size++;
            }

            prev->next = fast;  // Note!
            slow = fast;  // update slow
        }
    }

    return head;
}

ListNode *sortList(ListNode *head) 
{
    if(!head)
        return NULL;

    int step = 1;
    int size = 0;

    ListNode* ptr = head;
    while(ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }

    while(size > step)
    {
        ListNode* start = head;
        ListNode* prev = head;
        int to_sort_size = size;

        while(to_sort_size > step)
        {
            ListNode* list_1 = start;
            int size_1 = step;

            ListNode* list_2 = get_node_after_n_steps(start, size_1);
            int size_2 = ((to_sort_size-step) > step) ? step : (to_sort_size-step);

            start = get_node_after_n_steps(list_2, size_2);

            ListNode* sorted_head = NULL;
            ListNode* sorted_tail = NULL;
            merge_sort_list_in_place(list_1, size_1, list_2, size_2, &sorted_head, &sorted_tail);

            if(prev == head)
            {
                head = sorted_head;
                prev = sorted_tail;
            }
            else
            {
                prev->next = sorted_head;
                prev = sorted_tail;
            }

            // update
            to_sort_size -= (size_1 + size_2);
        }
        
        prev->next = start;  // Note!
        step = step << 1;
    }

    return head;
}

ListNode* get_node_after_n_steps(ListNode* node, int step)
{
    while(step > 0)
    {
        node = node->next;
        step--;
    }

    return node;
}

// 对两个链表进行归并排序
// 在参数中返回头尾节点的指针
int merge_sort_list_in_place(ListNode* list_1, int size_1, 
                    ListNode* list_2, int size_2, 
                    ListNode** head, 
                    ListNode** tail)
{
    ListNode* head_1 = list_1;
    ListNode* curr_1 = list_1;
    ListNode* prev_1 = list_1;

    ListNode* head_2 = list_2;
    ListNode* curr_2 = list_2;
    ListNode* prev_2 = list_2;

    while((size_1 > 0) && (size_2 > 0))
    {
        if(curr_1->val < curr_2->val)
        {
            prev_1 = curr_1;
            curr_1 = curr_1->next;

            size_1--;
        }
        else
        {
            ListNode* tmp = curr_2->next;
            // delete
            if(curr_2 == head_2)
            {
                head_2 = curr_2->next;
                prev_2 = curr_2->next;
            }
            else
            {
                prev_2->next = curr_2->next;
            }

            // insert
            if(curr_1 == head_1)
            {
                head_1 = curr_2;
                prev_1 = curr_2;
                curr_2->next = curr_1;
            }
            else
            {
                curr_2->next = prev_1->next;
                prev_1->next = curr_2;
                prev_1 = curr_2;
            }

            // update 
            curr_2 = tmp;

            size_2--;
        }
    }

    // if list_1 is NOT empty
    while(size_1 > 0)
    {
        prev_1 = curr_1;
        curr_1 = curr_1->next;
        size_1--;
    }

    *tail = prev_1;

    // if list_2 is NOT empty
    if(size_2 > 0)
    {
        prev_1->next = head_2;

        while(size_2 > 0)
        {
            prev_2 = curr_2;
            curr_2 = curr_2->next;
            size_2--;
        }
        
        *tail = prev_2;
    }

    *head = head_1;

    return 0;
}

