#include "random_linked_list.h"
#include <map>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

// 一种不需要额外辅助空间的巧妙解法
RandomListNode* copyRandomList_ii(RandomListNode* head)
{
    if(!head) return NULL;
    
    RandomListNode* ptr = head;
    // 插入新节点
    while(ptr != NULL)
    {        
        RandomListNode* node = new RandomListNode(ptr->label);
        node->next = ptr->next;
        ptr->next = node;

        ptr = node->next;
    }

    ptr = head;
    // 复制random
    while(ptr != NULL)
    {
        RandomListNode* node = ptr->next;
        node->random = (ptr->random != NULL) ? (ptr->random->next) : NULL;

        ptr = node->next;
    }

    //RandomListNode* copy_head = NULL;
    RandomListNode* copy = head->next;
    ptr = head;
    // 分解为两个链表
    while(ptr != NULL)
    {
        RandomListNode* tmp = ptr->next;
        ptr->next = tmp->next;

        if(tmp->next != NULL)
            tmp->next = tmp->next->next;

        ptr = ptr->next;
        //if(copy_head == NULL)
        //{
        //    copy_head = ptr->next;
        //}
        //else
        //{
        //    copy->next = ptr->next;
        //}
        //copy = ptr->next;
        //
        //ptr->next = copy->next;
        //ptr = copy->next;
    }

    return copy;
}

RandomListNode *copyRandomList(RandomListNode *head) 
{
    RandomListNode* copy = NULL;

    if(!head)
        return NULL;

    RandomListNode* src = head;
    RandomListNode* dest = copy;

    int index = 0;
    // Src Random List: Node Address -> Node Index
    map<RandomListNode*, int> hash_map;
    // Copy Random List: Node Index -> Node Address
    vector<RandomListNode*> address;

    while(src != NULL)
    {
        RandomListNode* node = new RandomListNode(src->label);
        if(copy == NULL)
        {
            copy = node;
            dest = node;
        }
        else
        {
            dest->next = node;
            dest = dest->next;
        }

        hash_map.insert(std::pair<RandomListNode*, int>(src, index));
        address.push_back(node);

        index++;
        src = src->next;
    }

    src = head;
    dest = copy;
    while(src && dest)
    {
        if(src->random == NULL)
        {
            dest->random = NULL;
        }
        else
        {
            int index = hash_map[src->random];
            dest->random = address[index];
        }

        src = src->next;
        dest = dest->next;
    }

    return copy;
}

