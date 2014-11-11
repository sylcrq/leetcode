#include "gtest/gtest.h"
#include "binary_tree.h"
#include <vector>

using namespace std;

TreeNode *buildTree_ii(vector<int> &preorder, vector<int> &inorder);


TEST(ConstructBinaryTreeFromPreorderAndInorderTraversalTestCase, Normal)
{
    int preorder[7] = {1,2,4,5,3,6,7};
    int inorder[7] = {4,2,5,1,6,3,7};

    vector<int> preorder_(preorder, preorder+7);
    vector<int> inorder_(inorder, inorder+7);

    TreeNode* root = buildTree_ii(preorder_, inorder_);

    binary_tree_print(root);
}
