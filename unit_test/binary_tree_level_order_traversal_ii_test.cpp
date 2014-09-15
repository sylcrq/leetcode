#include "gtest/gtest.h"
#include "binary_tree.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

vector<vector<int> > levelOrderBottom(TreeNode *root);

TEST(BinaryTreeLevelOrderTraversalIITestCase, Normal)
{
    vector<int> tree;
    tree.push_back(3);
    tree.push_back(9);
    tree.push_back(20);
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(15);
    tree.push_back(7);

    TreeNode* root = generate_binary_tree(tree);
    binary_tree_print(root);

    vector<vector<int> > result = levelOrderBottom(root);

    cout << "level order bottom:" << endl;
    for(vector<vector<int> >::iterator it = result.begin(); it != result.end(); it++)
    {
        for(vector<int>::iterator it_ = (*it).begin(); it_ != (*it).end(); it_++)
        {
            cout << *it_ << " - ";
        }
        cout << endl;
    }
}
