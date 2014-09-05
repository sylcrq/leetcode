#include <limits>
#include <queue>

#include "binary_tree.h"

using namespace std;

TreeNode* generate_binary_tree(vector<int>& tree)
{
    TreeNode* root = NULL;
    queue<TreeNode*> my_queue;  // 辅助队列

    if(tree.empty()) return root;

    root = new TreeNode(tree[0]);  //TODO: new failed
    my_queue.push(root);

    for(size_t i=1; i<tree.size(); )
    {
        TreeNode* tmp = my_queue.front();
        my_queue.pop();

        if(i<tree.size() && tree[i] != numeric_limits<int>::max())
        {
            tmp->left = new TreeNode(tree[i]);  //TODO: new failed
            my_queue.push(tmp->left);
        }

        i++;

        if(i<tree.size() && tree[i] != numeric_limits<int>::max())
        {
            tmp->right = new TreeNode(tree[i]);  //TODO: new failed
            my_queue.push(tmp->right);
        }

        i++;
    }

    return root;
}

void binary_tree_print(TreeNode* root)
{
    if(!root) return;

    queue<TreeNode*> my_queue;  // 辅助队列

    my_queue.push(root);

    while(!my_queue.empty())
    {
        TreeNode* tmp = my_queue.front();
        my_queue.pop();

        cout << tmp->val << "(";

        if(tmp->left)
        {
            cout << tmp->left->val;
            my_queue.push(tmp->left);
        }

        cout << ", ";

        if(tmp->right)
        {
            cout << tmp->right->val;
            my_queue.push(tmp->right);
        }

        cout << ")" << endl;
    }
}
