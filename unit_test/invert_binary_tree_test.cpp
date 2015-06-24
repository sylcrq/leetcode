#include "binary_tree.h"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

TreeNode* invertTree(TreeNode* root);

TEST(InvertBinaryTreeTestCase, Normal) {
    int test_tree[] = {4,2,7,1,3,6,9};
    vector<int> tree(test_tree, test_tree + sizeof(test_tree)/sizeof(int));

    TreeNode* root = generate_binary_tree(tree);
    binary_tree_print(root);

    std::cout << "after invert:" << std::endl;

    root = invertTree(root);
    binary_tree_print(root);
}
