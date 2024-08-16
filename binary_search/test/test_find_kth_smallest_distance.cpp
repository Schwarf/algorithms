//
// Created by andreas on 16.08.24.
//
#include "gtest/gtest.h"
#include "./../find_kth_smallest_distance.h"

TEST(TestFindKthSmallestDistanceBruteForce1, simple1) {
    std::vector<int> input{1, 3, 1};
    constexpr int k{1};
    constexpr int expected_result{};
    EXPECT_EQ(smallest_distance_pair_brute_force1(input, k), expected_result);
}

TEST(TestFindKthSmallestDistanceBruteForce1, simple2) {
    std::vector<int> input{1, 3, 1};
    constexpr int k{2};
    constexpr int expected_result{2};
    EXPECT_EQ(smallest_distance_pair_brute_force1(input, k), expected_result);
}

TEST(TestFindKthSmallestDistanceBruteForce1, simple3) {
    std::vector<int> input{1, 3, 1};
    constexpr int k{3};
    constexpr int expected_result{2};
    EXPECT_EQ(smallest_distance_pair_brute_force1(input, k), expected_result);
}

TEST(TestFindKthSmallestDistanceBruteForce1, simple4) {
    std::vector<int> input{1, 1, 1};
    constexpr int k{2};
    constexpr int expected_result{};
    EXPECT_EQ(smallest_distance_pair_brute_force1(input, k), expected_result);
}

TEST(TestFindKthSmallestDistanceBruteForce1, simple5) {
    std::vector<int> input{1, 6, 1};
    constexpr int k{3};
    constexpr int expected_result{5};
    EXPECT_EQ(smallest_distance_pair_brute_force1(input, k), expected_result);
}


TEST(TestFindKthSmallestDistanceBruteForce1, complex1) {
    std::vector<int> input{0, 2, 2, 1, 1, 1, 0, 2, 2, 0, 1, 2, 2, 1, 2, 1, 1, 0, 0, 0, 1, 0, 0, 2, 2, 0, 1, 0, 1, 1, 1,
                           1, 0, 2, 0, 1, 2, 2, 0, 0, 2, 1, 2, 0, 2, 2, 0, 0, 1, 2, 2, 2, 1, 2, 0, 0, 0, 2, 2, 0, 2, 1,
                           2, 2, 1, 0, 2, 2, 1, 1, 1, 2, 0, 2, 2, 0, 0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 2, 0, 2, 2, 2,
                           1, 1, 2, 2, 0, 1, 2, 1, 2, 0, 2, 0, 0, 2, 2, 0, 0, 1, 0, 2, 2, 1, 0, 2, 1, 0, 2, 2, 2, 0, 1,
                           0, 2, 1, 0, 2, 0, 1, 1, 2, 0, 0, 1, 1, 2, 2, 0, 2, 1, 2, 1, 2, 2, 1, 0, 0, 0, 0, 0, 2, 0, 1,
                           2, 0, 0, 0, 2, 1, 2, 2, 0, 2, 2, 0, 0, 1, 0, 0, 0, 2, 0, 2, 1, 0, 0, 0, 2, 1, 0, 1, 0, 2, 1,
                           2, 2, 0, 0, 2, 0, 2, 1, 0, 2, 1, 1, 0, 0};
    constexpr int k{10000};
    constexpr int expected_result{1};
    EXPECT_EQ(smallest_distance_pair_brute_force1(input, k), expected_result);
}
