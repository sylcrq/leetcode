#include "random_linked_list.h"

using namespace std;

RandomListNode* init_random_linked_list(vector<int>& value)
{
    RandomListNode* head = NULL;

    if(value.empty())
        return head;

    RandomListNode* ptr = head;

    for(vector<int>::iterator it=value.begin(); it != value.end(); it++)
    {
        RandomListNode* node = new RandomListNode(*it);
        if(head == NULL)
        {
            head = node;
            ptr = node;
        }
        else
        {
            ptr->next = node;
            ptr = ptr->next;
        }
    }

    // set random pointer
    ptr = head;
    while(ptr != NULL)
    {
        ptr->random = ptr;
        ptr = ptr->next;
    }

    return head;
}

void print_random_linked_list(RandomListNode* head)
{
    if(!head) return;

    RandomListNode* ptr = head;

    while(ptr != NULL)
    {
        std::cout << ptr->label << "[" << ptr << "],";

        if(ptr->random == NULL)
            std::cout << "NULL ->";
        else
            std::cout << ptr->random->label << "[" << ptr->random << "] ->";

        ptr = ptr->next;
    }

    std::cout << std::endl;
}

