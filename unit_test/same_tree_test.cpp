#include "gtest/gtest.h"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q);

//void AddtoLeft(TreeNode* root, TreeNode* p)
//{
//    root->left = p;
//}

//void AddtoRight(TreeNode* root, TreeNode* p)
//{
//    root->right = p;
//}

TEST(SameTreeTestCase, Normal)
{
//    TreeNode* p = new TreeNode(1);
//    AddtoLeft(p, new TreeNode(2));
//    AddtoRight(p, new TreeNode(3));
//
//    TreeNode* q = new TreeNode(1);
//    AddtoLeft(q, new TreeNode(2));
//    AddtoRight(q, new TreeNode(3));

//    EXPECT_EQ(true, isSameTree(p, q));
}
