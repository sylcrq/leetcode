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
int maxDepth_recursive(TreeNode *root)
{
    if(!root) return 0;

    int left = 1 + maxDepth_recursive(root->left);
    int right = 1 + maxDepth_recursive(root->right);

    return std::max(left, right);
}

//非递归
int maxDepth(TreeNode *root)
{
    int max = 0;
    std::stack< std::pair<TreeNode*, int> > my_stack;

    //初始状态入栈
    my_stack.push(std::make_pair(root, 0));

    while(!my_stack.empty())
    {
        TreeNode* node = my_stack.top().first;
        int depth = my_stack.top().second;
        //栈顶元素出栈
        my_stack.pop();

        if(!node)
        {
            continue;
        }
        else
        {
            depth += 1;
            my_stack.push(std::make_pair(node->left, depth));
            my_stack.push(std::make_pair(node->right, depth));

            max = std::max(max, depth);
        }
    }

    return max;
}
