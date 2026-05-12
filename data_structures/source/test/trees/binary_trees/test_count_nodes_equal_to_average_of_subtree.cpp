//
// Created by andreas on 12.05.26.
//

#include "gtest/gtest.h"
#include "setup_binary_tree.h"
#include "trees/binary_trees/count_nodes_equal_to_average_of_subtree.h"

TEST_F(SetupBinaryTree, CountNodesEqualToAverageOfSubtreeEmptyTree)
{
    TreeNode<int>* root = nullptr;
    EXPECT_EQ(averageOfSubtree(root), 0);
}

TEST_F(SetupBinaryTree, CountNodesEqualToAverageOfSubtreeSmallTree)
{
    auto root = small_binary_tree_root();
    EXPECT_EQ(averageOfSubtree(root), 3);
}

TEST_F(SetupBinaryTree, CountNodesEqualToAverageOfSubtreeFullTree)
{
    auto root = binary_tree_root();
    EXPECT_EQ(averageOfSubtree(root), 9);
}

TEST_F(SetupBinaryTree, CountNodesEqualToAverageOfSubtreeDuplicateSubtrees)
{
    auto root = medium_tree_with_subtree_duplicates2();
    EXPECT_EQ(averageOfSubtree(root), 4);
}

TEST_F(SetupBinaryTree, CountNodesEqualToAverageOfSubtreePalindromicTree)
{
    auto root = palindromic_tree1();
    EXPECT_EQ(averageOfSubtree(root), 4);
}
