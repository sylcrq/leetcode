#include <iostream>
#include <vector>

// Definition for singly-linked list with a random pointer.
struct RandomListNode 
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// create and init a singly-linked list with a random pointer
RandomListNode* init_random_linked_list(std::vector<int>& value);

void print_random_linked_list(RandomListNode* head);

