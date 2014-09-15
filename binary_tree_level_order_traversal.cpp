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

