#include <limits>
#include <vector>

#include "gtest/gtest.h"
#include "binary_tree.h"

using namespace std;

vector<int> preorderTraversal(TreeNode* root);
vector<int> inorderTraversal(TreeNode *root);
vector<int> postorderTraversal(TreeNode *root);

TEST(BinaryTreeXOrderTraversalTestCase, Normal)
{
    vector<int> tree;
    // {1, 2, 3, 4, 5, #, 6, 7, #, #, 8, 9, 10}
    tree.push_back(1);
    tree.push_back(2);
    tree.push_back(3);
    tree.push_back(4);
    tree.push_back(5);
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(6);
    tree.push_back(7);
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(numeric_limits<int>::max());
    tree.push_back(8);
    tree.push_back(9);
    tree.push_back(10);

    TreeNode* root = generate_binary_tree(tree);

    vector<int> preorder_result = preorderTraversal(root);
    vector<int> inorder_result = inorderTraversal(root);
    vector<int> postorder_result = postorderTraversal(root);

    cout << "preorder: ";

    for(size_t i=0; i<preorder_result.size(); i++)
    {
        cout << preorder_result[i] << " - ";
    }

    cout << endl << "inorder: ";

    for(size_t i=0; i<inorder_result.size(); i++)
    {
        cout << inorder_result[i] << " - ";
    }

    cout << endl << "postorder: ";

    for(size_t i=0; i<postorder_result.size(); i++)
    {
        cout << postorder_result[i] << " - ";
    }

    cout << endl;
}
