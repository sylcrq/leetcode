#include <stack>
#include "binary_tree.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root != NULL) {
            mystack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(mystack.empty())
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = mystack.top();
        int val = tmp->val;
        mystack.pop();

        if(tmp->right != NULL) {
            tmp = tmp->right;
            while(tmp != NULL) {
                mystack.push(tmp);
                tmp = tmp->left;
            }
        }

        return val;
    }

private:
    std::stack<TreeNode*> mystack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

