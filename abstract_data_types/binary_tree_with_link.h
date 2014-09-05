#ifndef _BINARY_TREE_WITH_LINK_H_
#define _BINARY_TREE_WITH_LINK_H_

#include <iostream>

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


//Insert a New TreeLinkNode
TreeLinkNode* binary_tree_with_link_insert(TreeLinkNode* root, int val);

//Print
void binary_tree_with_link_print(TreeLinkNode* root);

#endif
