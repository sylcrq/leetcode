#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB)
        return NULL;

    ListNode* tmpA = headA;
    int numA = 0;
    while(tmpA != NULL) {
        numA++;
        tmpA = tmpA->next;
    }

    ListNode* tmpB = headB;
    int numB = 0;
    while(tmpB != NULL) {
        numB++;
        tmpB = tmpB->next;
    }

    int diff = (numA>numB) ? (numA-numB) : (numB-numA);

    tmpA = headA;
    tmpB = headB;

    if(numA > numB) {
        while(diff > 0) {
            tmpA = tmpA->next;
            diff--;
        }
    } else {
        while(diff > 0) {
            tmpB = tmpB->next;
            diff--;
        }
    }

    while(tmpA != NULL && tmpB != NULL) {
        if(tmpA == tmpB)
            return tmpA;

        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }

    return NULL;
}

