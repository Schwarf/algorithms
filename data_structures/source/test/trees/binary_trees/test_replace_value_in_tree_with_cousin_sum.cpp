//
// Created by andreas on 23.10.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/replace_value_in_tree_with_cousin_sum.h"
#include "trees/binary_trees/pre_order_traversal.h"

TEST_F(SetupBinaryTree, TestCousinReplacementSimple1)
{
    auto tree = small_binary_tree_root();
    auto expected_result = std::vector<unsigned int> (5);
    auto tree_result = replace_values_with_cousin_sum_bfs(tree);
    auto result = pre_order_traversal(tree_result);
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupBinaryTree, TestCousinReplacementSimple2)
{
    auto tree = medium_tree_with_subtree_duplicates1();
    auto expected_result = std::vector<unsigned int> {0, 0, 6, 0 ,4 , 0, 4};
    auto tree_result = replace_values_with_cousin_sum_bfs(tree);
    auto result = pre_order_traversal(tree_result);
    EXPECT_EQ(result, expected_result);
}