#include "binary_tree.h"
#include "gtest/gtest.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void flatten(TreeNode *root);

TEST(FlattenBinaryTreeToLinkedListTestCase, Normal)
{
    vector<int> tree;
    tree.push_back(1);
    tree.push_back(2);
    tree.push_back(5);
    tree.push_back(3);
    tree.push_back(4);
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(6);

    TreeNode* root = generate_binary_tree(tree);
    binary_tree_print(root);

    std::cout << "after:" << std::endl;

    flatten(root);
    binary_tree_print(root);
}
