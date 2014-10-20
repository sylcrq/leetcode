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

vector<TreeNode*> generateTrees_helper(int start, int end);

vector<TreeNode *> generateTrees(int n) 
{
    return generateTrees_helper(1, n);
}

// 递归函数
vector<TreeNode*> generateTrees_helper(int start, int end)
{
    vector<TreeNode*> ret;

    if(start > end)
    {
        ret.push_back(NULL);
        return ret;
    }

    for(int i=start; i<=end; i++)
    {
        vector<TreeNode*> left = generateTrees_helper(start, i-1);
        vector<TreeNode*> right = generateTrees_helper(i+1, end);

        for(vector<TreeNode*>::iterator it=left.begin(); it != left.end(); it++)
        {
            for(vector<TreeNode*>::iterator it_=right.begin(); it_ != right.end(); it_++)
            {
                TreeNode* node = new TreeNode(i);
                node->left = *it;
                node->right = *it_;

                ret.push_back(node);
            }
        }
    }

    return ret;
}

