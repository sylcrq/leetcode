#include <stack>
#include <vector>

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

vector<int> g_preorder_result;
// 递归
vector<int> preorderTraversal_recursive(TreeNode *root)
{
    if(!root) return g_preorder_result;

    g_preorder_result.push_back(root->val);

    preorderTraversal_recursive(root->left);
    preorderTraversal_recursive(root->right);

    return g_preorder_result;
}

// 非递归
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> my_stack;  // 辅助栈

    if(!root) return result;

    my_stack.push(root);

    while(!my_stack.empty())
    {
        TreeNode* tmp = my_stack.top();
        my_stack.pop();

        result.push_back(tmp->val);

        // right child node
        if(tmp->right)
            my_stack.push(tmp->right);

        // left child node
        if(tmp->left)
            my_stack.push(tmp->left);
    }

    return result;
}
