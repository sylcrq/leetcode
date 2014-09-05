#include <queue>

#include "binary_tree_with_link.h"


//Insert a New TreeLinkNode
//使用广度优先的策略插入新节点
TreeLinkNode* binary_tree_with_link_insert(TreeLinkNode* root, int val)
{
    TreeLinkNode* ret = root;

    std::queue<TreeLinkNode*> myqueue;  //辅助队列

    TreeLinkNode* node = new TreeLinkNode(val);
    //TODO:

    if(!root)
    {
        ret = node;
    }
    else
    {
        myqueue.push(root);

    	while(!myqueue.empty())
        {
            TreeLinkNode* tmp = myqueue.front();
            if(NULL == tmp->left)
            {
                tmp->left = node;
                break;
            }
            else if(NULL == tmp->right)
            {
                tmp->right = node;
                break;
            }
            else
            {
                myqueue.push(tmp->left);
                myqueue.push(tmp->right);
                myqueue.pop();
            }
        }
    }

    return ret;
}

//Print
//广度优先遍历
void binary_tree_with_link_print(TreeLinkNode* root)
{
    if(!root) return;

    int level = 0;
    int max_nodes = 1;

    std::queue<TreeLinkNode*> myqueue;  // 辅助队列

    myqueue.push(root);

    while(!myqueue.empty())
    {
        TreeLinkNode* tmp = myqueue.front();

        if(tmp->next)
            std::cout << tmp->val << "(" << tmp->next->val << ")"  << " - ";
        else
	    std::cout << tmp->val << "(" << "null" << ")" << " - ";

        if(NULL != tmp->left)
            myqueue.push(tmp->left);

        if(NULL != tmp->right)
            myqueue.push(tmp->right);

        myqueue.pop();
        
        max_nodes--;
        if(0 == max_nodes)
        {
            level++;
            max_nodes = (1 << level);

            std::cout << std::endl;
        }
    }
}

