#include "binary_tree.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder);

TEST(ConstructBinaryTreeFromInorderAndPostorderTraversalTestCase, Normal)
{
    int inorder[7] = {4,2,5,1,6,3,7};
    int postorder[7] = {4,5,2,6,7,3,1};

    vector<int> inorder_(inorder, inorder+7);
    vector<int> postorder_(postorder, postorder+7);

    TreeNode* root = buildTree(inorder_, postorder_);

    binary_tree_print(root);
}

TEST(ConstructBinaryTreeFromInorderAndPostorderTraversalTestCase, LeftIsNull)
{
    int inorder[2] = {1,2};
    int postorder[2] = {2,1};

    vector<int> inorder_(inorder, inorder+2);
    vector<int> postorder_(postorder, postorder+2);

    TreeNode* root = buildTree(inorder_, postorder_);

    binary_tree_print(root);
}
