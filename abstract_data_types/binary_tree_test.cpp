#include "gtest/gtest.h"
#include "binary_tree.h"

#include <limits>

using namespace std;

TEST(BinaryTreeTestCase, Normal)
{
    vector<int> tree;
    // {1, 2, 3, #, #, 4, #, #, 5}
    tree.push_back(1);
    tree.push_back(2);
    tree.push_back(3);
    tree.push_back(numeric_limits<int>::max());  // #
    tree.push_back(numeric_limits<int>::max());  // #
    tree.push_back(4);
    tree.push_back(numeric_limits<int>::max());  // #
    tree.push_back(numeric_limits<int>::max());  // #
    tree.push_back(5);

    TreeNode* root = generate_binary_tree(tree);

    binary_tree_print(root);

    //TODO: free
}
