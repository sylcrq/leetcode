#include <vector>

#include "binary_tree.h"

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


void insert_to_bst(TreeNode* node, vector<int>& num, int left_start, int left_end, int right_start, int right_end);
TreeNode* insert_to_bst_ii(vector<int>& num, int start, int end);

TreeNode *sortedArrayToBST(vector<int> &num)
{
    // solution 1
#if 0
    TreeNode* root = NULL;

    if(num.size() > 0)
    {
        int position = (num.size() - 1) / 2;

        root = new TreeNode(num[position]);

        insert_to_bst(root, num, 0, position-1, position+1, num.size() - 1);
    }

    return root;
#endif

    // solution 2
#if 1
    return insert_to_bst_ii(num, 0, num.size() - 1);
#endif
}

void insert_to_bst(TreeNode* node, vector<int>& num, int left_start, int left_end, int right_start, int right_end)
{
    if(!node) return;

    if(left_start <= left_end)
    {
        int position = left_start + (left_end - left_start) / 2;

        TreeNode* tmp = new TreeNode(num[position]);
        node->left = tmp;

        insert_to_bst(node->left, num, left_start, position-1, position+1, left_end);
    }

    if(right_start <= right_end)
    {
        int position = right_start + (right_end - right_start) / 2;

        TreeNode* tmp = new TreeNode(num[position]);
        node->right = tmp;

        insert_to_bst(node->right, num, right_start, position-1, position+1, right_end);
    }
}

// 优化, 简洁的代码逻辑
TreeNode* insert_to_bst_ii(vector<int>& num, int start, int end)
{
    if(start > end)
        return NULL;

    int position = start + (end - start) / 2;

    TreeNode* node = new TreeNode(num[position]);

    node->left = insert_to_bst_ii(num, start, position-1);
    node->right = insert_to_bst_ii(num, position+1, end);

    return node;
}
