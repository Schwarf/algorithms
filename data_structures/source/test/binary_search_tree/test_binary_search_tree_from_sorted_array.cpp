//
// Created by andreas on 03.08.22.
//
#include "gtest/gtest.h"
#include "../../binary_search_tree/binary_search_tree_from_sorted_array.h"
#include "test_helper.h"


TEST(binary_search_tree_from_sorted_array, simple_array)
{
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto root = binary_search_tree_from_sorted_array<int>(input);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
}

TEST(binary_search_tree_from_sorted_array, long_array)
{
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 18, 20, 26, 31, 56, 78, 89, 109, 1010, 12091, 188888};
    auto root = binary_search_tree_from_sorted_array<int>(input);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
}
