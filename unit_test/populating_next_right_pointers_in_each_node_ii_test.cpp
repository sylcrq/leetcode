#include "binary_tree_with_link.h"
#include "gtest/gtest.h"

#include <iostream>

void connect_ii(TreeLinkNode *root);
void connect_ii_v2(TreeLinkNode *root);


TEST(PopulatingNextRightPointersInEachNodeIITestCase, Normal)
{
    TreeLinkNode* root = NULL;

    root = binary_tree_with_link_insert(root, 1);
    root = binary_tree_with_link_insert(root, 2);
    root = binary_tree_with_link_insert(root, 3);
    root = binary_tree_with_link_insert(root, 4);
    root = binary_tree_with_link_insert(root, 5);
    root = binary_tree_with_link_insert(root, 6);
    root = binary_tree_with_link_insert(root, 7);

    binary_tree_with_link_print(root);

    //connect_ii(root);
    connect_ii_v2(root);

    std::cout << std::endl;
    binary_tree_with_link_print(root);
}
