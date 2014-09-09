#include "gtest/gtest.h"
#include "binary_tree.h"

#include <limits>
#include <vector>

using namespace std;

bool isSymmetric(TreeNode *root);

TEST(SymmetricTreeTestCase, Normal)
{
    vector<int> tree;
    tree.push_back(1);
    tree.push_back(2);
    tree.push_back(2);
    tree.push_back(3);
    tree.push_back(4);
    tree.push_back(4);
    tree.push_back(3);
    tree.push_back(5);
    tree.push_back(6);
    tree.push_back(7);
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(7);
    tree.push_back(6);
    tree.push_back(5);

    TreeNode* root = generate_binary_tree(tree);

    binary_tree_print(root);

    EXPECT_TRUE(isSymmetric(root));
}
