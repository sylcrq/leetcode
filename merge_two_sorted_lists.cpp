/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//往List中添加Node
ListNode* AddListNode(ListNode* head, ListNode* node)
{
    if(!head && !node) return NULL;
    else if(!head && node) return node;
    else if(head && !node) return head;

    ListNode* ptr = head;

    while(ptr->next)
        ptr = ptr->next;

    ptr->next = node;    

    return head;
}

//打印List中所有Node
void PrintList(ListNode* head)
{
    if(!head) return;

    ListNode* ptr = head;

    do {
        std::cout << ptr->val << " - ";
        ptr = ptr->next;
    }while(ptr);

    std::cout << std::endl;
}

//时间复杂度O(n)
//参考林应老师的代码,优化了一下代码逻辑,删除一些冗余的代码
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(!l1 && !l2) return NULL;
    if(!l1) return l2;
    if(!l2) return l1;

    //ListNode* merged = NULL;
    //ListNode* merged_it = merged;

    //用head和tail表示merge后的新链表
    ListNode* head = NULL;
    ListNode* tail = NULL;

    //tmp指向要插入的node
    ListNode* tmp = NULL;

    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            tmp = l1;
            l1 = l1->next;
            //if(!merged_it)
            //{
            //    merged = l1;
            //    merged_it = l1;
            //}
            //else
            //{
            //    merged_it->next = l1;
            //    merged_it = merged_it->next;
            //}

            //l1 = l1->next;
            //merged_it->next = NULL;
        }
        else
        {
            tmp = l2;
            l2 = l2->next;
            //if(!merged_it)
            //{
            //    merged = l2;
            //    merged_it = l2;
            //}
            //else
            //{
            //    merged_it->next = l2;
            //    merged_it = merged_it->next;
            //}

            //l2 = l2->next;
            //merged_it->next = NULL;
        }

        if(!head && !tail)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }

    }

    if(l1)
    {
        //merged_it->next = l1;
        tail->next = l1;
    }

    if(l2)
    {
        //merged_it->next = l2;
        tail->next = l2;
    }

    return head;
}
