#include "gtest/gtest.h"
#include "binary_tree_with_link.h"

extern void connect(TreeLinkNode *root);
extern void connect_recursive(TreeLinkNode* root);

TEST(PopulatingNextRightPointersinEachNodeTestCase, Normal)
{
    TreeLinkNode* root = NULL;
    root = binary_tree_with_link_insert(root, 1);
    root = binary_tree_with_link_insert(root, 2);
    root = binary_tree_with_link_insert(root, 3);
    root = binary_tree_with_link_insert(root, 4);
    root = binary_tree_with_link_insert(root, 5);
    root = binary_tree_with_link_insert(root, 6);
    root = binary_tree_with_link_insert(root, 7);

    std::cout << "before connect:" << std::endl;
    binary_tree_with_link_print(root);

    connect(root);

    std::cout << "after connect:" << std::endl;
    binary_tree_with_link_print(root);

    //TODO: release memory
}


TEST(PopulatingNextRightPointersinEachNodeTestCase, Recursive)
{
    TreeLinkNode* root = NULL;
    root = binary_tree_with_link_insert(root, 1);
    root = binary_tree_with_link_insert(root, 2);
    root = binary_tree_with_link_insert(root, 3);
    root = binary_tree_with_link_insert(root, 4);
    root = binary_tree_with_link_insert(root, 5);
    root = binary_tree_with_link_insert(root, 6);
    root = binary_tree_with_link_insert(root, 7);

    std::cout << "before connect_recursive:" << std::endl;
    binary_tree_with_link_print(root);

    connect_recursive(root);

    std::cout << "after connect_recursive:" << std::endl;
    binary_tree_with_link_print(root);

    //TODO: release memory
}

