//
// Created by andreas on 03.08.22.
//

#include "gtest/gtest.h"
#include "trees/binary_trees/flatten_binary_search_tree_to_array.h"
#include "trees/binary_trees/binary_search_tree_from_sorted_array.h"


TEST(flatten_binary_search_tree_to_array, first_attempt) {
    std::vector<int> prep{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto input = binary_search_tree_from_sorted_array<int>(prep);

    auto result = flatten_binary_search_tree<int>(input);
    EXPECT_EQ(prep, result);
}


TEST(flatten_binary_search_tree_to_array, second_attempt) {
    std::vector<int> prep{-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 189, 2901, 1920910, 290192012};
    auto input = binary_search_tree_from_sorted_array<int>(prep);

    auto result = flatten_binary_search_tree<int>(input);
    EXPECT_EQ(prep, result);
}
