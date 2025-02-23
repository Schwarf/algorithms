//
// Created by andreas on 23.02.25.
//

#include "trees/binary_trees/construct_binary_tree_from_preorder_traversal.h"
#include "trees/binary_trees/pre_order_traversal.h"
#include "gtest/gtest.h"

TEST(TestConstructBinaryTreeFromPreorderTraversal, simple1)
{
    std::string input{"1-2--3--4-5--6--7"};
    auto tree = new TreeNode<int>(1);
    tree->left = new TreeNode<int>(2);
    tree->right = new TreeNode<int>(5);
    tree->left->left = new TreeNode<int>(3);
    tree->left->right = new TreeNode<int>(4);
    tree->right->left = new TreeNode<int>(6);
    tree->right->right = new TreeNode<int>(7);

    auto result = construct_binary_tree_from_preorder<int>(input);
    EXPECT_EQ(pre_order_traversal(result), pre_order_traversal(tree));
}

