#include "binary_tree.h"
#include <limits.h>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isValidBST(TreeNode *root) 
{
    if(!root)
        return true;

    bool left_is_bst = isValidBST(root->left);
    bool right_is_bst = isValidBST(root->right);

    if(left_is_bst && right_is_bst)
    {
        TreeNode* left_max_node = root->left;
        TreeNode* right_min_node = root->right;

        // find the max node in left subtree
        if(left_max_node != NULL)
        {
            while(left_max_node->right != NULL)
            {
                left_max_node = left_max_node->right;
            }
        }

        // find the min node in right subtree
        if(right_min_node != NULL)
        {
            while(right_min_node->left != NULL)
            {
                right_min_node = right_min_node->left;
            }
        }

        if( (left_max_node == NULL || left_max_node->val < root->val) && 
            (right_min_node == NULL || right_min_node->val > root->val) )
            return true;
    }

    return false;
}

