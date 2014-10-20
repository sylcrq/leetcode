#include "binary_tree.h"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

vector<TreeNode *> generateTrees(int n);

TEST(UniqueBinarySearchTreesIITestCase, Normal)
{
    vector<TreeNode*> result = generateTrees(3);

    for(vector<TreeNode*>::iterator it=result.begin(); it != result.end(); it++)
    {
        TreeNode* root = *it;

        binary_tree_print(root);
        std::cout << std::endl;
    }
}

