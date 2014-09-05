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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //递归
    bool hasPathSum_recursive(TreeNode *root, int sum) 
    {
        if(!root) return false;

        if(!root->left && !root->right && root->val == sum)
            return true;

        return hasPathSum_recursive(root->left, sum - root->val) || hasPathSum_recursive(root->right, sum - root->val);
    }

    //非递归
    bool hasPathSum(TreeNode *root, int sum)
    {
        std::stack< std::pair<TreeNode*, int> > my_stack;

        //初始状态入栈
        my_stack.push(std::make_pair(root, sum));

        while(!my_stack.empty())
        {
            TreeNode* node = my_stack.top().first;
            int value = my_stack.top().second;

            my_stack.pop();

            if(!node) continue;

            if(!node->left && !node->right && node->val == value)
                return true;

            my_stack.push(std::make_pair(node->left, value - node->val));
            my_stack.push(std::make_pair(node->right, value - node->val));
        }

        return false;
    }
};
