//
// Created by andreas on 25.01.26.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/split_binary_tree.h"

TEST_F(SetupBinaryTree, split_binary_tree_null_root)
{
    // Tree:
    //     1
    //    / \
    //   2   3
    //
    // Total = 6, target = 3
    // Cut edge (1 -> 3) => sums 3 and 3 => should return 3.
    TreeNode<int> * root = nullptr;

    EXPECT_EQ(split_binary_tree(root), 0);
}


TEST_F(SetupBinaryTree, split_binary_tree_Positive_SimpleCut)
{
    // Tree:
    //     1
    //    / \
    //   2   3
    //
    // Total = 6, target = 3
    // Cut edge (1 -> 3) => sums 3 and 3 => should return 3.
    auto root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);

    EXPECT_EQ(split_binary_tree(root), 3);
}

TEST_F(SetupBinaryTree, split_binary_tree_Negative_OddTotal)
{
    // Total = 5 (odd) => impossible
    auto root = small_tree_with_subtree_duplicates();
    EXPECT_EQ(split_binary_tree(root), 0);
}

TEST_F(SetupBinaryTree, split_binary_tree_Negative_EvenButNoCut)
{
    // Total = 54, target = 27, but no subtree sums to 27 => 0
    auto root = small_binary_tree_root();
    EXPECT_EQ(split_binary_tree(root), 0);
}

TEST_F(SetupBinaryTree, split_binary_tree_Negative_LargerProvidedTree_NoCut)
{
    // Subtree sums: left=6, right=10, leaves 2/3/4/5 => none is 9 => 0
    auto root = medium_tree_with_subtree_duplicates3();
    EXPECT_EQ(split_binary_tree(root), 0);
}

TEST_F(SetupBinaryTree, SplitBinaryTree_Positive_GrandchildCut)
{
    //       0
    //      / \
    //     1   1
    //        / \
    //       2   0
    //
    // Total = 4, target = 2
    // Subtree rooted at node '2' is a grandchild; cut edge (1 -> 2) => 2 and 2
    auto root = new TreeNode<int>(0);
    root->left = new TreeNode<int>(1);
    root->right = new TreeNode<int>(1);
    root->right->left = new TreeNode<int>(2);
    root->right->right = new TreeNode<int>(0);

    EXPECT_EQ(split_binary_tree(root), 2);
}

TEST_F(SetupBinaryTree, SplitBinaryTree_Positive_LargerTree_SubtreeHalf) {
    //                 0
    //              /     \
    //             7       7
    //           /  \    /  \
    //          3    4  3    4
    //         / \    \ / \    \
    //        1  2     3 1  2    3
    //
    // Each side sums to: 7 + 3 + 4 + 1 + 2 + 3 = 20
    // Total = 40, target = 20
    // Cut (0 -> left 7) or (0 -> right 7) => 20 and 20 => return 20.

    auto root = new TreeNode<int>(0);

    // Left subtree (sum 20)
    root->left = new TreeNode<int>(7);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->left->left->left = new TreeNode<int>(1);
    root->left->left->right = new TreeNode<int>(2);
    root->left->right->right = new TreeNode<int>(3);

    // Right subtree (sum 20)
    root->right = new TreeNode<int>(7);
    root->right->left = new TreeNode<int>(3);
    root->right->right = new TreeNode<int>(4);
    root->right->left->left = new TreeNode<int>(1);
    root->right->left->right = new TreeNode<int>(2);
    root->right->right->right = new TreeNode<int>(3);

    EXPECT_EQ(split_binary_tree(root), 20);
}
