#include <queue>

#include "binary_tree_with_link.h"

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

//assume that it is a perfect binary tree 
//(ie, all leaves are at the same level, and every parent has two children)

// 一种使用递归的巧妙实现
void connect_recursive(TreeLinkNode* root)
{
    if(!root) return;

    if(NULL != root->left)
        root->left->next = root->right;

    if(NULL != root->right)
    {
        if(NULL != root->next)
            root->right->next = root->next->left;
        else
            root->right->next = NULL;
    }

    connect_recursive(root->left);
    connect_recursive(root->right);
}

void connect(TreeLinkNode *root)
{
    if(!root) return;

    std::queue<TreeLinkNode*> myqueue;  // 辅助队列
    int level = 0;      // 树的深度
    int max_nodes = 1;  // 树深度为level时的最大节点数

    myqueue.push(root);

    while( !myqueue.empty() )
    {
        TreeLinkNode* tmp = myqueue.front();

	if(NULL != tmp->left)
	    myqueue.push( tmp->left );

        if(NULL != tmp->right)
	    myqueue.push( tmp->right );

        myqueue.pop();

        max_nodes--;
	if(0 == max_nodes)
	{
	    level++;
	    max_nodes = (1 << level);

	    tmp->next = NULL;
	}
	else
	{
	    tmp->next = myqueue.front();
	}
    }
}

