#include "binary_tree.h"
#include "gtest/gtest.h"
#include <vector>
#include <limits>

using namespace std;

int minDepth(TreeNode *root);

TEST(MinimumDepthOfBinaryTreeTestCase, Normal)
{
    vector<int> tree;

    tree.push_back(1);
    tree.push_back(2);
    tree.push_back(3);
    tree.push_back(4);
    tree.push_back(5);
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(6);
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(7);

    TreeNode* root = generate_binary_tree(tree);
    binary_tree_print(root);

    EXPECT_EQ(3, minDepth(root));
}
