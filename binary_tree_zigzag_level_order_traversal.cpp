#include "binary_tree.h"
#include <algorithm>
#include <queue>
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

vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
{
    vector<vector<int> > result;

    if(!root) return result;

    queue<TreeNode*> my_queue;
    my_queue.push(root);

    vector<int> level_nodes;
    int current_level_nodes_num = 1;
    int next_level_nodes_num = 0;
    int current_level = 0;

    while(!my_queue.empty())
    {
        TreeNode* node = my_queue.front();
        my_queue.pop();

        level_nodes.push_back(node->val);
        current_level_nodes_num--;

        if(node->left)
        {
            my_queue.push(node->left);
            next_level_nodes_num++;
        }

        if(node->right)
        {
            my_queue.push(node->right);
            next_level_nodes_num++;
        }

        if(current_level_nodes_num == 0)
        {
            current_level_nodes_num = next_level_nodes_num;
            next_level_nodes_num = 0;

            if(current_level & 0x1)
            {
                std::reverse(level_nodes.begin(), level_nodes.end());
                result.push_back(level_nodes);
            }
            else
            {
                result.push_back(level_nodes);
            }

            level_nodes.resize(0);
            current_level++;
        }
    }

    return result;
}

