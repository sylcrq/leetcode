#include <vector>
#include "binary_tree.h"

using namespace std;

TreeNode* buildTree_helper_ii(vector<int>& preorder, int pre_start, int pre_end, 
                           vector<int>& inorder, int in_start, int in_end);

TreeNode *buildTree_ii(vector<int> &preorder, vector<int> &inorder) 
{
    return buildTree_helper_ii(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);    
}

TreeNode* buildTree_helper_ii(vector<int>& preorder, int pre_start, int pre_end, 
                           vector<int>& inorder, int in_start, int in_end)
{
    if(pre_start > pre_end || in_start > in_end)
        return NULL;

    int parent_val = preorder[pre_start];

    // find parent node in inorder
    int position = in_start;
    for(; position<=in_end; position++)
    {
        if(inorder[position] == parent_val)
            break;
    }

    int left_node_num = position - in_start;

    TreeNode* parent = new TreeNode(parent_val);

    parent->left = buildTree_helper_ii(preorder, pre_start+1, pre_start+left_node_num, 
                                    inorder, in_start, position-1);
    parent->right = buildTree_helper_ii(preorder, pre_start+left_node_num+1, pre_end, 
                                     inorder, position+1, in_end);

    return parent;
}

