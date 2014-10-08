#include <stack>
#include <utility>
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

// iterative solution
int sumNumbers(TreeNode *root)
{
    int result = 0;
    int value = 0;  // root to leaf number
    int level = 0;  // current tree depth

    if(!root) return result;

    stack<pair<TreeNode*, int> > my_stack;
    my_stack.push(make_pair(root, 0));

    while(!my_stack.empty())
    {
        TreeNode* tmp_node = my_stack.top().first;
        int tmp_level = my_stack.top().second;

        my_stack.pop();

        if(tmp_level > level)
        {
            value = value*10 + tmp_node->val;
        }
        else if(tmp_level < level)
        {
            int i = level - tmp_level;
            while(i > 0)
            {
                value = value / 10;
                i--;
            }

            value = value / 10;
            value = value*10 + tmp_node->val;
        }
        else
        {
            value = value / 10;
            value = value*10 + tmp_node->val;
        }

        level = tmp_level;

        if(tmp_node->left == NULL && tmp_node->right == NULL)
        {
            // leaf node
            result += value;
        }
        else 
        {
            if(tmp_node->left != NULL)
            {
                my_stack.push(make_pair(tmp_node->left, tmp_level+1));
            }

            if(tmp_node->right != NULL)
            {
                my_stack.push(make_pair(tmp_node->right, tmp_level+1));
            }
        }
    }

    return result;
}

void sumNumbers_recursive(TreeNode* node, int& result, int value);

// recursive solution
int sumNumbers_ii(TreeNode *root) 
{
    int result = 0;
    int value = 0;

    sumNumbers_recursive(root, result, value);

    return result;
}

void sumNumbers_recursive(TreeNode* node, int& result, int value)
{
    if(node == NULL) return;

    value = value*10 + node->val;

    if(node->left == NULL && node->right == NULL)
    {
        result += value;
        return;
    }

    if(node->left)
        sumNumbers_recursive(node->left, result, value);

    if(node->right)
        sumNumbers_recursive(node->right, result, value);
}

