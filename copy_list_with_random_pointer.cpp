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

