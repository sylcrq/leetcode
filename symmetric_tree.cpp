#include "binary_tree.h"

#include <stack>

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

bool is_symmetric_tree(TreeNode* left, TreeNode* right);
bool is_symmetric_tree_ii(TreeNode* root);

bool isSymmetric(TreeNode *root)
{
    // solution 1:
    if(!root) return true;
    
    return is_symmetric_tree(root->left, root->right);

    // solution 2:
    //return is_symmetric_tree_ii(root);
}

// 递归 - recursively 
bool is_symmetric_tree(TreeNode* left, TreeNode* right)
{
    if(left == NULL && right == NULL)
        return true;
    
    if(left != NULL && right != NULL)
    {
        if(left->val != right->val)
            return false;

        if(!is_symmetric_tree(left->left, right->right))
            return false;

        if(!is_symmetric_tree(left->right, right->left))
            return false;

        return true;
    }

    return false;
}

// 非递归 - iteratively
bool is_symmetric_tree_ii(TreeNode* root)
{
    stack<TreeNode*> lstack;  // 辅助栈
    stack<TreeNode*> rstack;

    if(!root) return true;

    lstack.push(root->left);
    rstack.push(root->right);

    while(!lstack.empty() && !rstack.empty())
    {
        TreeNode* ltmp = lstack.top();
        TreeNode* rtmp = rstack.top();

        lstack.pop();
        rstack.pop();

        if(ltmp == NULL && rtmp == NULL)
        {
            continue;
        }
        else if(ltmp != NULL && rtmp != NULL)
        {
            if(ltmp->val != rtmp->val)
                return false;

            lstack.push(ltmp->left);
            lstack.push(ltmp->right);
            rstack.push(rtmp->right);
            rstack.push(rtmp->left);
        }
        else
        {
            return false;
        }
    }

    return true;
}

