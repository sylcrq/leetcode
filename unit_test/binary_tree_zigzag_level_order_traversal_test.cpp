#include "gtest/gtest.h"
#include "binary_tree.h"
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<vector<int> > zigzagLevelOrder(TreeNode *root);

TEST(BinaryTreeZigzagLevelOrderTraversalTestCase, Normal)
{
    vector<int> tree;
    tree.push_back(3);
    tree.push_back(9);
    tree.push_back(20);
    tree.push_back(INT_MAX);
    tree.push_back(INT_MAX);
    tree.push_back(15);
    tree.push_back(7);

    TreeNode* root = generate_binary_tree(tree);
    binary_tree_print(root);

    vector<vector<int> > result = zigzagLevelOrder(root);

    std::cout << "print:" << std::endl;

    for(vector<vector<int> >::iterator it=result.begin(); it != result.end(); it++)
    {
        for(vector<int>::iterator it_ = (*it).begin(); it_ != (*it).end(); it_++)
        {
            std::cout << *it_ << ", ";
        }

        std::cout << std::endl;
    }
}
