#include "binary_tree.h"
#include "gtest/gtest.h"
#include <limits>
#include <vector>

using namespace std;

int sumNumbers(TreeNode *root);
int sumNumbers_ii(TreeNode *root); 

TEST(SumRootToLeafNumbersTestCase, Normal)
{
    vector<int> tree;

    tree.push_back(1);
    tree.push_back(2);
    tree.push_back(3);
    tree.push_back(4);
    tree.push_back(5);
    tree.push_back(6);
    tree.push_back(7);
    tree.push_back(8);
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(9);

    TreeNode* root = generate_binary_tree(tree);

    binary_tree_print(root);

    EXPECT_EQ(2780, sumNumbers(root));
    EXPECT_EQ(2780, sumNumbers_ii(root));
}
