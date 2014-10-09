#include "binary_tree.h"
#include <limits>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void minDepth_recursive(TreeNode* node, int& min, int depth);

// recursive solution
int minDepth(TreeNode *root) 
{
    if(!root) return 0;

    int min = std::numeric_limits<int>::max();
    int depth = 0;

    minDepth_recursive(root, min, depth);

    return min;
}

void minDepth_recursive(TreeNode* node, int& min, int depth)
{
    if(node == NULL) return;

    depth += 1;

    if(node->left == NULL && node->right == NULL)
    {
        // leaf
        min = (depth < min) ? depth : min;
    }

    minDepth_recursive(node->left, min, depth);
    minDepth_recursive(node->right, min, depth);
}

