#include <vector>

#include "gtest/gtest.h"
#include "binary_tree.h"

using namespace std;

TreeNode *sortedArrayToBST(vector<int> &num);


TEST(ConvertSortedArrayToBinarySearchTreeTestCase, Normal)
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
    tree.push_back(9);
    tree.push_back(10);
    tree.push_back(11);
    tree.push_back(12);


    TreeNode* root = sortedArrayToBST(tree);

    binary_tree_print(root);
}
