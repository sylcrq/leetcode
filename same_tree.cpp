/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <stack>
#include <utility>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归
bool isSameTree_recursive(TreeNode *p, TreeNode *q)
{
    if(!p && !q)
        return true;
    if(!p || !q)
        return false;

    return (p->val == q->val) && 
            isSameTree_recursive(p->left, q->left) && 
            isSameTree_recursive(p->right, q->right);
}

//非递归
bool isSameTree(TreeNode *p, TreeNode *q)
{
    bool same = true;

    std::stack< std::pair<TreeNode*, TreeNode*> > my_stack;
    //初始状态入栈
    my_stack.push(std::make_pair(p, q));

    while(!my_stack.empty())
    {
        TreeNode* tmp_p = my_stack.top().first;
        TreeNode* tmp_q = my_stack.top().second;

        my_stack.pop();

        if(!tmp_p && !tmp_q)
        {
            continue;
        }
        else if(!tmp_p || !tmp_q)
        {
            return false;
        }
        else
        {
            if(tmp_p->val != tmp_q->val)
                return false;

            my_stack.push(std::make_pair(tmp_p->left, tmp_q->left));
            my_stack.push(std::make_pair(tmp_p->right, tmp_q->right));
        }
    }

    return same;
}

