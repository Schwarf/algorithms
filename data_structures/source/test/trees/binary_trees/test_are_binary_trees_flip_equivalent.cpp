//
// Created by andreas on 24.10.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/are_binary_trees_flip_equivalent.h"

TEST_F(SetupBinaryTree, TestAreBinaryTreeFlipEquivalent1)
{
    auto tree1 = new TreeNode<int>(0);
    tree1->left = new TreeNode<int>(1);
    tree1->right = new TreeNode<int>(2);
    tree1->left->right = new TreeNode<int>(3);

    auto tree2 = new TreeNode<int>(0);
    tree2->left = new TreeNode<int>(1);
    tree2->right = new TreeNode<int>(2);
    tree2->right->right = new TreeNode<int>(3);

    EXPECT_FALSE(are_flip_equivalent_recursive(tree1, tree2));
}

TEST_F(SetupBinaryTree, TestAreBinaryTreeFlipEquivalent2)
{
    auto tree1 = small_binary_tree_root();
    auto tree2 = tree1;
    std::swap(tree1->left, tree1->right);

    EXPECT_TRUE(are_flip_equivalent_recursive(tree1, tree2));
}

TEST_F(SetupBinaryTree, TestAreBinaryTreeFlipEquivalent3)
{
    TreeNode<unsigned int>* tree1 = nullptr;
    auto tree2 = inverted_tree();

    EXPECT_FALSE(are_flip_equivalent_recursive(tree1, tree2));
}

TEST_F(SetupBinaryTree, TestAreBinaryTreeFlipEquivalent4)
{
    TreeNode<unsigned int>* tree1 = nullptr;
    auto tree2  = tree1;

    EXPECT_TRUE(are_flip_equivalent_recursive(tree1, tree2));
}

TEST_F(SetupBinaryTree, TestAreBinaryTreeFlipEquivalent5)
{
    auto tree1 = new TreeNode<int>(1);
    tree1->left = new TreeNode<int>(2);
    tree1->right = new TreeNode<int>(3);
    tree1->left->left = new TreeNode<int>(4);
    tree1->left->right = new TreeNode<int>(5);
    tree1->left->right->left = new TreeNode<int>(7);
    tree1->left->right->right = new TreeNode<int>(8);
    tree1->right->left = new TreeNode<int>(6);

    auto tree2 = new TreeNode<int>(1);
    tree2->left = new TreeNode<int>(3);
    tree2->right = new TreeNode<int>(2);
    tree2->right->left = new TreeNode<int>(4);
    tree2->right->right = new TreeNode<int>(5);
    tree2->right->right->left = new TreeNode<int>(7);
    tree2->right->right->right = new TreeNode<int>(8);
    tree2->left->right = new TreeNode<int>(6);

    EXPECT_TRUE(are_flip_equivalent_recursive(tree1, tree2));
}



