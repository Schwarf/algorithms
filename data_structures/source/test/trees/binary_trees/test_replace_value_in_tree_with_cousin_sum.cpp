//
// Created by andreas on 23.10.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/replace_value_in_tree_with_cousin_sum.h"
#include "trees/binary_trees/pre_order_traversal.h"
#include "trees/binary_trees/level_order_traversal.h"

TEST_F(SetupBinaryTree, TestCousinReplacementSimple1) {
    auto tree = small_binary_tree_root();
    auto expected_result = std::vector<unsigned int>(5);
    auto tree_result = replace_values_with_cousin_sum_bfs(tree);
    auto result = pre_order_traversal(tree_result);
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupBinaryTree, TestCousinReplacementSimple2) {
    auto tree = medium_tree_with_subtree_duplicates1();
    auto expected_result = std::vector<unsigned int>{0, 0, 6, 0, 4, 0, 4};
    auto tree_result = replace_values_with_cousin_sum_bfs(tree);
    auto result = pre_order_traversal(tree_result);
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupBinaryTree, TestCousinReplacementSimple3) {
    auto tree = new TreeNode<float>(5.f);
    auto expected_result = std::vector<float>{0.f};
    auto tree_result = replace_values_with_cousin_sum_bfs(tree);
    auto result = pre_order_traversal(tree_result);
    EXPECT_EQ(result, expected_result);
}

template<typename T>
std::vector<T> flatten(const std::vector<std::vector<T>>& vec) {
    std::vector<T> flattened;

    for (const auto& inner_vector : vec) {
        flattened.insert(flattened.end(), inner_vector.begin(), inner_vector.end());
    }

    return flattened;
}

TEST_F(SetupBinaryTree, TestCousinReplacementSimple4) {
    auto tree = binary_tree_root();
    auto expected_result = std::vector<unsigned int>{0, 0, 0, 105, 105, 32, 32, 273, 273, 247, 247, 214, 214, 133, 133};
    auto tree_result = replace_values_with_cousin_sum_bfs(tree);
    auto result = flatten(level_order_traversal(tree_result));
    EXPECT_EQ(result, expected_result);
}