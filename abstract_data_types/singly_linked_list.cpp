#include "singly_linked_list.h"



//Add a New ListNode
//在链表尾部添加一个新节点
//成功返回链表头指针
//失败返回NULL
ListNode* singly_linked_list_add(ListNode* head, int val)
{
    ListNode* ret = head;

    ListNode* node = new ListNode(val);
    //TODO: new failed

    if(!head)
    {
        ret = node;
    }
    else
    {
        while(head->next != NULL)
            head = head->next;

        head->next = node;
    }

    return ret;
}

//Remove a ListNode
//删除链表中指定节点
//成功返回链表头指针
//失败返回NULL
ListNode* singly_linked_list_remove(ListNode* head, ListNode* node)
{
    if(!head || !node) return NULL;

    ListNode* ret = head;

    if(head == node)
    {
        ret = node->next;
    }
    else
    {        
        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr)
        {
            if(curr == node)
            {
                prev->next = node->next;
                break;
            }

            prev = curr;
            curr = curr->next;
        }
    }

    //release memory
    delete node;

    return ret;
}

//Search 
//链表中查找指定元素
//成功返回第一次出现该元素的节点指针
//未找到返回NULL
ListNode* singly_linked_list_search(ListNode* head, int val)
{
    ListNode* ret = NULL;

    while(head != NULL)
    {
        if(val == head->val)
        {
            ret = head;
            break;
        }

        head = head->next;
    }

    return ret;
}


//Traverse
//遍历并打印链表节点
void singly_linked_list_traverse(ListNode* head)
{
    while(head)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }

    std::cout << std::endl;
}


//Cycle
//在链表中生成一个环
//使链表最后一个节点的next指针指向它之前的某个节点
void singly_linked_list_cycle(ListNode* head, ListNode* node)
{
    if(!head || !node) return;

    ListNode* tmp = head;
    
    while(tmp->next)
        tmp = tmp->next;

    tmp->next = node;
}
