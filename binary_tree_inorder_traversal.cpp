#include <stack>
#include <utility>
#include <vector>

#include "binary_tree.h"

using namespace std;

// 非递归
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    stack<pair<TreeNode*, int> > my_stack;  // 辅助栈

    if(!root) return result;

    my_stack.push(make_pair(root, 0));

    while(!my_stack.empty())
    {
        TreeNode* tmp = my_stack.top().first;

        // left child node非空, 并且没有被访问过
        if(tmp->left && my_stack.top().second == 0)
        {
            my_stack.top().second = 1;

            my_stack.push(make_pair(tmp->left, 0));
        }
        else
        {
            result.push_back(tmp->val);

            my_stack.pop();

            // right child node
            if(tmp->right)
            {
                my_stack.push(make_pair(tmp->right, 0));
            }
        }
    }

    return result;
}
