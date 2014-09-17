#include "binary_tree.h"

#include <iostream>
#include <vector>
#include <queue>

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

struct TreeNodeInfo
{
    TreeNode* node;
    int level;

    TreeNodeInfo(TreeNode* ptr, int n) : node(ptr), level(n) {}
};

// solution 1
vector<vector<int> > levelOrder(TreeNode *root)
{
    vector<vector<int> > result;

    queue<TreeNodeInfo> my_queue;  // 辅助队列

    if(root != NULL)
    {
        TreeNodeInfo node(root, 0);
        my_queue.push(node);
    }

    while(!my_queue.empty())
    {
        TreeNodeInfo tmp = my_queue.front();

        my_queue.pop();

        //cout << (tmp.node)->val << "-" << tmp.level << endl;
        if(result.size() == tmp.level)
        {
            vector<int> v;
            v.push_back((tmp.node)->val);
            result.push_back(v);
        }
        else
        {
            result[tmp.level].push_back((tmp.node)->val);
        }

        if((tmp.node)->left != NULL)
        {
            TreeNodeInfo node((tmp.node)->left, tmp.level + 1);
            my_queue.push(node);
        }

        if((tmp.node)->right != NULL)
        {
            TreeNodeInfo node((tmp.node)->right, tmp.level + 1);
            my_queue.push(node);
        }
    }

    return result;
}

// solution 2
// BFS (Breadth-First Search)
vector<vector<int> > levelOrder_ii(TreeNode* root)
{
    vector<vector<int> > result;

    queue<TreeNode*> my_queue;  // 辅助队列
    vector<int> level_nodes;    // Level Tree Nodes

    int next_level_nodes = 0;
    int current_level_nodes = 0;

    if(root != NULL)
    {
        my_queue.push(root);
        current_level_nodes++;
    }


    while(!my_queue.empty())
    {
        TreeNode* tmp = my_queue.front();
        my_queue.pop();

        level_nodes.push_back(tmp->val);

        if(tmp->left != NULL)
        {
            my_queue.push(tmp->left);
            next_level_nodes++;
        }

        if(tmp->right != NULL)
        {
            my_queue.push(tmp->right);
            next_level_nodes++;
        }

        current_level_nodes--;
        if(current_level_nodes == 0)
        {
            result.push_back(level_nodes);
            level_nodes.resize(0);

            current_level_nodes = next_level_nodes;
            next_level_nodes = 0;
        }
    }

    return result;
}
