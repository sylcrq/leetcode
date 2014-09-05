#include <stack>
#include <utility>
#include <vector>

#include "binary_tree.h"

using namespace std;

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode*> my_stack;  // 辅助栈
    stack<pair<int, int> > my_stack_info;  // 辅助栈

    if(!root) return result;

    my_stack.push(root);
    my_stack_info.push(make_pair(0, 0));

    while(!my_stack.empty())
    {
        TreeNode* tmp = my_stack.top();

        // left child node非空,并且没有被访问过
        if(tmp->left && my_stack_info.top().first == 0)
        {
            my_stack_info.top().first = 1;

            my_stack.push(tmp->left);
            my_stack_info.push(make_pair(0, 0));
        }
        // right child node非空,并且没有被访问过
        else if(tmp->right && my_stack_info.top().second == 0)
        {
            my_stack_info.top().second = 1;

            my_stack.push(tmp->right);
            my_stack_info.push(make_pair(0, 0));
        }
        else
        {
            result.push_back(tmp->val);

            my_stack.pop();
            my_stack_info.pop();
        }
    }

    return result;
}
