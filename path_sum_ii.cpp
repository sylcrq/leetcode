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

// 递归
void pathSum_helper(vector<vector<int> >& result, vector<int>& path, int path_sum, TreeNode* node, int sum);

vector<vector<int> > pathSum(TreeNode *root, int sum)
{
    vector<vector<int> > result;
    vector<int> path;
    int path_sum = 0;

    if(!root)
        return result;

    pathSum_helper(result, path, path_sum, root, sum);

    return result;
}

void pathSum_helper(vector<vector<int> >& result, vector<int>& path, int path_sum, TreeNode* node, int sum)
{
    path.push_back(node->val);
    path_sum += node->val;
    
    // root-to-leaf paths where each path's sum equals the given sum
    if(sum == path_sum && NULL == node->left && NULL == node->right)
    {
        result.push_back(path);
        return;
    }

    if(node->left)
    {
        pathSum_helper(result, path, path_sum, node->left, sum);
        path.pop_back();
    }

    if(node->right)
    {
        pathSum_helper(result, path, path_sum, node->right, sum);
        path.pop_back();
    }
}

