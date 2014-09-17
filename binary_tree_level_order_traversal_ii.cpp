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

vector<vector<int> > levelOrder(TreeNode *root);
vector<vector<int> > levelOrder_ii(TreeNode* root);

vector<vector<int> > levelOrderBottom(TreeNode *root)
{
    //vector<vector<int> > result = levelOrder(root);
    vector<vector<int> > result = levelOrder_ii(root);

    if(!result.empty())
        reverse(result.begin(), result.end());

    return result;
}

