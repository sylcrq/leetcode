#include <stack>
#include "binary_tree.h"

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// pre-order traversal
// 扩展: in-order ? recursive ?
void flatten(TreeNode *root) 
{
    if(!root) return;

    stack<TreeNode*> my_stack;
    my_stack.push(root);

    TreeNode* list_tail = root;

    while(!my_stack.empty())
    {
        TreeNode* node = my_stack.top();
        my_stack.pop();

        if(node->right != NULL)
        {
            my_stack.push(node->right);
        }

        if(node->left != NULL)
        {
            my_stack.push(node->left);
        }

        // insert into linked list 
        node->left = NULL;
        node->right = NULL;

        if(node != root)
        {
            list_tail->right = node;
            list_tail = node;
        }
    }

}

