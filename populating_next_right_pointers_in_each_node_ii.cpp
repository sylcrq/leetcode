#include "binary_tree_with_link.h"
#include <queue>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// solution 1: 广度优先遍历
// 使用的空间大小还可以优化
void connect_ii(TreeLinkNode *root)
{
    if(!root) return;

    queue<TreeLinkNode*> my_queue;  // 辅助队列

    my_queue.push(root);

    int level_nodes_num = 1;       // 当前level的node数
    int next_level_nodes_num = 0;  // 下一level的node数

    while(!my_queue.empty())
    {
        TreeLinkNode* node = my_queue.front();
        my_queue.pop();

        if(node->left != NULL)
        {
            my_queue.push(node->left);
            next_level_nodes_num++;
        }

        if(node->right != NULL)
        {
            my_queue.push(node->right);
            next_level_nodes_num++;
        }

        level_nodes_num--;
        if(level_nodes_num > 0)
        {
            node->next = my_queue.front();
        }
        else
        {
            level_nodes_num = next_level_nodes_num;
            next_level_nodes_num = 0;
        }

    }
}

// solution 2: 通过上一level已经建立好的节点间的next关系
// 空间复杂度: O(1)
void connect_ii_v2(TreeLinkNode *root)
{
    if(!root) return;

    TreeLinkNode* level = root;  // 当前level第一个node

    while(level != NULL)
    {
        TreeLinkNode* head = NULL;  // 下一level第一个node
        TreeLinkNode* prev = NULL;

        for(TreeLinkNode* node=level; node != NULL; node=node->next)
        {
            if(!node->left && !node->right)
                continue;

            // 获取下一level的第一个node
            if(!head)
                head = (node->left != NULL) ? node->left : node->right;
            
            if(node->left)
            {
                if(prev != NULL)
                    prev->next = node->left;

                prev = node->left;
            }

            if(node->right)
            {
                if(prev != NULL)
                    prev->next = node->right;

                prev= node->right;
            }
        }

        // update level
        level = head;
    }
}

