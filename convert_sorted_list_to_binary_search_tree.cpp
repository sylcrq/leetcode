#include "binary_tree.h"
#include "singly_linked_list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* sortedListToBST_helper(ListNode*& head, int start, int end);

TreeNode *sortedListToBST(ListNode *head) 
{
    int count = 0;
    ListNode* ptr = head;

    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    ptr = head;
    return sortedListToBST_helper(ptr, 1, count);
}

// 按照链表的顺序递归的创建balanced BST
// Bottom-To-Top (有点像中序遍历)
TreeNode* sortedListToBST_helper(ListNode*& head, int start, int end)
{
    if(start > end) return NULL;

    int mid = (start + end) / 2;

    TreeNode* left = sortedListToBST_helper(head, start, mid-1);

    TreeNode* node = new TreeNode(head->val);
    node->left = left;

    head = head->next;  // Note!

    node->right = sortedListToBST_helper(head, mid+1, end);

    return node;
}

