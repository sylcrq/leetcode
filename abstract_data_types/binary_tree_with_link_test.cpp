#include "gtest/gtest.h"
#include "binary_tree_with_link.h"


TEST(BinaryTreeWithLinkTestCase, Normal)
{
    TreeLinkNode* root = NULL;

    root = binary_tree_with_link_insert(root, 1);
    root = binary_tree_with_link_insert(root, 2);
    root = binary_tree_with_link_insert(root, 3);
    root = binary_tree_with_link_insert(root, 4);
    root = binary_tree_with_link_insert(root, 5);
    root = binary_tree_with_link_insert(root, 6);
    root = binary_tree_with_link_insert(root, 7);
    root = binary_tree_with_link_insert(root, 8);
    root = binary_tree_with_link_insert(root, 9);
    
    binary_tree_with_link_print(root);
}
