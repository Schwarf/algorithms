//
// Created by andreas on 29.04.24.
//

#include "gtest/gtest.h"
#include "./../count_operations_to_make_xor_of_array_equal_k.h"

TEST(TestCountOperationsToMakeXOROfArrayEequalK, simple1) {
    const std::vector<int> input{2, 1, 3, 4};
    constexpr int k{1};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, count_operations(input, k));
}

TEST(TestCountOperationsToMakeXOROfArrayEequalK, simple2) {
    const std::vector<int> input{2, 0, 2, 0};
    constexpr int k{0};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, count_operations(input, k));
}


TEST(TestCountOperationsToMakeXOROfArrayEequalK, simple3) {
    const std::vector<int> input{5, 5, 5, 5};
    constexpr int k{5};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, count_operations(input, k));
}

TEST(TestCountOperationsToMakeXOROfArrayEequalK, simple4) {
    const std::vector<int> input{5, 5, 5};
    constexpr int k{5};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, count_operations(input, k));
}

TEST(TestCountOperationsToMakeXOROfArrayEequalK, simple5) {
    const std::vector<int> input{2,1,3,4, 100, 88, 21031, 9021};
    constexpr int k{511};
    constexpr int expected_result{9};
    EXPECT_EQ(expected_result, count_operations(input, k));
}


