//
// Created by andreas on 16.04.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/insert_row_into_tree.h"

TEST_F(SetupBinaryTree, TestInsertRowIntoTree) {
    constexpr int input_tree_index{};
    constexpr int output_tree_index{1};
    constexpr int value_index{2};
    constexpr int depth_index{3};
    auto tuple = tree_and_inserted_row_tree<float>();
    auto input_tree = std::get<input_tree_index>(tuple);
    auto depth = std::get<depth_index>(tuple);
    auto value = std::get<value_index>(tuple);
    auto expected_tree = std::get<input_tree_index>(tuple);
}