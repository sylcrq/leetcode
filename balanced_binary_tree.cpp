#include <algorithm>
#include <stdlib.h>

#include "binary_tree.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool is_balanced(TreeNode* node, int& height);


bool isBalanced(TreeNode *root)
{
    int height;

    return is_balanced(root, height);
}

bool is_balanced(TreeNode* node, int& height)
{
    if(!node)
    {
        height = 0;
        return true;
    }

    int left_height;
    int right_height;

    if(false == is_balanced(node->left, left_height))
        return false;

    if(false == is_balanced(node->right, right_height))
        return false;

    height = std::max(left_height, right_height) + 1;

    if(abs(left_height - right_height) > 1)
        return false;

    return true;
}

