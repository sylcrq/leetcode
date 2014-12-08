#include "gtest/gtest.h"
#include "binary_tree.h"
#include <limits.h>
#include <vector>

using namespace std;

void recoverTree(TreeNode *root);

TEST(RecoverBinarySearchTreeTestCase, Normal)
{
    vector<int> tree;
    tree.push_back(1);
    tree.push_back(INT_MAX);
    tree.push_back(2);
    tree.push_back(3);

    TreeNode* root = generate_binary_tree(tree);

    binary_tree_print(root);   

    recoverTree(root);

    binary_tree_print(root);
}
