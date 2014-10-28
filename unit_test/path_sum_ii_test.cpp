#include "gtest/gtest.h"
#include "binary_tree.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

vector<vector<int> > pathSum(TreeNode *root, int sum);

TEST(PathSumIITestCase, RootIsNull)
{
    vector<vector<int> > result = pathSum(NULL, 1);

    EXPECT_TRUE(result.empty());
}

TEST(PathSumIITestCase, Normal)
{
    vector<int> tree;
    tree.push_back(5);
    tree.push_back(4);
    tree.push_back(8);
    tree.push_back(11);
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(13);
    tree.push_back(4);
    tree.push_back(7);
    tree.push_back(2);
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(5);
    tree.push_back(1);

    TreeNode* root = generate_binary_tree(tree);
    binary_tree_print(root);

    vector<vector<int> > result = pathSum(root, 22);

    std::cout << "Path Sum:" << std::endl;
    for(vector<vector<int> >::iterator it=result.begin(); it != result.end(); it++)
    {
        std::cout << "[";

        for(vector<int>::iterator it2=(*it).begin(); it2 != (*it).end(); it2++)
        {
            std::cout << *it2 << ",";
        }

        std::cout << "]" << std::endl;
    }

    //TODO: delete binary tree
}

