#include "gtest/gtest.h"
#include "binary_tree.h"
#include <limits.h>
#include <vector>

using namespace std;

bool isValidBST(TreeNode *root);

TEST(ValidateBinarySearchTreeTestCase, Normal)
{
    vector<int> tree;
    tree.push_back(1);
    tree.push_back(INT_MAX);
    tree.push_back(2);
    tree.push_back(3);

    TreeNode* root = generate_binary_tree(tree);

    binary_tree_print(root);

    EXPECT_FALSE( isValidBST(root) );
}

TEST(ValidateBinarySearchTreeTestCase, DuplicateNode)
{
    vector<int> tree;
    tree.push_back(1);
    tree.push_back(1);

    TreeNode* root = generate_binary_tree(tree);

    binary_tree_print(root);

    EXPECT_FALSE( isValidBST(root) );
}

TEST(ValidateBinarySearchTreeTestCase, RootIsIntMin)
{
    vector<int> tree;
    tree.push_back(INT_MIN);

    TreeNode* root = generate_binary_tree(tree);

    binary_tree_print(root);

    EXPECT_TRUE( isValidBST(root) );
}
