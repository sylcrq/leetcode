#include "binary_tree.h"
#include <algorithm>
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

void inorder_traversal(TreeNode* root, vector<TreeNode*>& tree_inorder, vector<int>& val_inorder);

// A solution using O(N) space
void recoverTree(TreeNode *root)
{
    if(!root) return;

    vector<TreeNode*> tree_inorder;
    vector<int> val_inorder;

    inorder_traversal(root, tree_inorder, val_inorder);

    // sort
    std::sort(val_inorder.begin(), val_inorder.end());

    for(size_t i=0; i<tree_inorder.size(); i++)
    {
        tree_inorder[i]->val = val_inorder[i];
    }

}

void inorder_traversal(TreeNode* root, vector<TreeNode*>& tree_inorder, vector<int>& val_inorder)
{
    if(!root) return;

    inorder_traversal(root->left, tree_inorder, val_inorder);

    tree_inorder.push_back(root);
    val_inorder.push_back(root->val);

    inorder_traversal(root->right, tree_inorder, val_inorder);
}

