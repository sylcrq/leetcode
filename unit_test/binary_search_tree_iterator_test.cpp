#include "binary_search_tree_iterator.h"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

TEST(BinarySearchTreeIteratorTestCase, Normal) {
    int test_tree[] = {4,2,6,1,3,5,7};
    vector<int> tree(test_tree, test_tree + sizeof(test_tree)/sizeof(int));

    TreeNode* root = generate_binary_tree(tree);
    binary_tree_print(root);

    std::cout << "BSTIterator:" << std::endl;

    BSTIterator i = BSTIterator(root);
    while(i.hasNext()) {
        std::cout << i.next() << std::endl;
    }
}
