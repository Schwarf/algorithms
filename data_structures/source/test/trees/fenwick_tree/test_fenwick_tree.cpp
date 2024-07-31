//
// Created by andreas on 31.07.24.
//

#include <gtest/gtest.h>
#include "trees/fenwick_tree/fenwick_tree.h"  // Include your Fenwick Tree implementation

// Test Initialization with Data
TEST(FenwickTreeTest, InitializesCorrectlyWithData) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    FenwickTree<int> fenwick_tree(data);
    constexpr int expected_result{15};
    EXPECT_EQ(fenwick_tree.get_sum(0, 4), expected_result);
}

// Test Single Update
TEST(FenwickTreeTest, HandlesSingleUpdate) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    FenwickTree<int> fenwick_tree(data);
    fenwick_tree.update(2, 5); // Update index 2 to add 5
    constexpr int expected_result{20};
    EXPECT_EQ(fenwick_tree.get_sum(0, 4), expected_result);
}

// Test Range Query
TEST(FenwickTreeTest, HandlesRangeQuery) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    FenwickTree<int> fenwick_tree(data);
    constexpr int expected_result{9};
    EXPECT_EQ(fenwick_tree.get_sum(1, 3), expected_result); // Sum from index 1 to 3
}

// Test Updates at Boundaries
TEST(FenwickTreeTest, UpdatesAtBoundaries) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    FenwickTree<int> fenwick_tree(data);
    fenwick_tree.update(0, 1); // Update first element
    fenwick_tree.update(4, 1); // Update last element
    constexpr int expected_result_update1{2};
    constexpr int expected_result_update2{6};
    EXPECT_EQ(fenwick_tree.get_sum(0, 0), expected_result_update1);
    EXPECT_EQ(fenwick_tree.get_sum(4, 4), expected_result_update2);
}
