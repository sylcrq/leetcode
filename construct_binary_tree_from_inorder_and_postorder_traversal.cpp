#include "binary_tree.h"
#include <vector>

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

// You may assume that duplicates do not exist in the tree.
TreeNode* buildTree_helper(vector<int>& inorder, int in_start, int in_end, 
                           vector<int>& postorder, int post_start, int post_end);


TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
{
    if(inorder.empty() || postorder.empty())
        return NULL;

    return buildTree_helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}

TreeNode* buildTree_helper(vector<int>& inorder, int in_start, int in_end, 
                           vector<int>& postorder, int post_start, int post_end)
{
    if(in_start > in_end || post_start > post_end)
        return NULL;

    int parent_num = postorder[post_end];

    // find "parent_num" in inorder
    int i = in_start;
    for(i=in_start; i<=in_end; i++)
    {
        if(inorder[i] == parent_num)
            break;
    }

    int size = i - in_start;

    TreeNode* parent = new TreeNode(parent_num);
    // TODO: new failed ?

    // [in_start, i-1] & [post_start, post_start+size-1]
    parent->left = buildTree_helper(inorder, in_start, i-1, postorder, post_start, post_start+size-1);
    // [i+1, in_end] & [post_start+size, post_end-1]
    parent->right = buildTree_helper(inorder, i+1, in_end, postorder, post_start+size, post_end-1);

    return parent;
}

