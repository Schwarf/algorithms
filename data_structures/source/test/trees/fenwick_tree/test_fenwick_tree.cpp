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

// Test Initialization with floating-point numbers
TEST(FenwickTreeTest, InitializesCorrectlyWithFloats) {
    std::vector<double> data = {0.1, 0.2, 0.3, 0.4, 0.5};
    FenwickTree<double> ft(data);
    EXPECT_NEAR(ft.get_sum(0, 4), 1.5, 1e-5);
}

// Test updates with max int
TEST(FenwickTreeTest, HandleMaxIntUpdates) {
    std::vector<int> data = {0, 0, 0, 0, 0};
    FenwickTree<int> ft(data);
    ft.update(2, std::numeric_limits<int>::max());
    EXPECT_EQ(ft.get_sum(2, 2), std::numeric_limits<int>::max());
}

// Test update with negative values
TEST(FenwickTreeTest, HandlesNegativeUpdates) {
    std::vector<int> data = {5, 5, 5, 5, 5};
    FenwickTree<int> ft(data);
    ft.update(2, -3);
    EXPECT_EQ(ft.get_sum(0, 4), 22);
}

// Floating point precision test
TEST(FenwickTreeTest, FloatingPointPrecision) {
    std::vector<float> data = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    FenwickTree<float> ft(data);
    ft.update(0, 0.000001f);
    ft.update(4, -0.000001f);
    EXPECT_NEAR(ft.get_sum(0, 4), 5.0f, 1e-5);
}