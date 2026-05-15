//
// Created by andreas on 15.05.26.
//

#include "gtest/gtest.h"
#include "setup_binary_tree.h"
#include "trees/binary_trees/maximum_product_of_splitted_tree.h"

TEST_F(SetupBinaryTree, MaximumProductOfSplittedTreeEmptyTree)
{
    TreeNode<int>* root = nullptr;
    EXPECT_EQ(get_maximum_product(root), 0);
}

TEST_F(SetupBinaryTree, MaximumProductOfSplittedTreeSingleNode)
{
    auto root = new TreeNode<int>(7);
    EXPECT_EQ(get_maximum_product(root), 0);
}

TEST_F(SetupBinaryTree, MaximumProductOfSplittedTreeSmallTree)
{
    auto root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);

    EXPECT_EQ(get_maximum_product(root), 9);
}

TEST_F(SetupBinaryTree, MaximumProductOfSplittedTreeLeetCodeExample)
{
    auto root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);

    EXPECT_EQ(get_maximum_product(root), 110);
}

TEST_F(SetupBinaryTree, MaximumProductOfSplittedTreeSkewedTree)
{
    auto root = new TreeNode<int>(1);
    root->right = new TreeNode<int>(2);
    root->right->right = new TreeNode<int>(3);
    root->right->right->right = new TreeNode<int>(4);

    EXPECT_EQ(get_maximum_product(root), 24);
}

TEST_F(SetupBinaryTree, MaximumProductOfSplittedTreeProvidedFullTree)
{
    auto root = binary_tree_root();
    EXPECT_EQ(get_maximum_product(root), 65540);
}
