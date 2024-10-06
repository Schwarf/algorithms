//
// Created by andreas on 06.10.24.
//
#include "./../make_divisible_by_value.h"
#include "gtest/gtest.h"

TEST(TestMakeDivisibleByValueBruteForce, simple1) {
    std::vector<int> input{3, 1, 4, 2};
    constexpr int value{6};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, min_size_of_subarray_brute_force(input, value));
}

TEST(TestMakeDivisibleByValueBruteForce, simple2) {
    std::vector<int> input{6, 3, 5, 2};
    constexpr int value{9};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, min_size_of_subarray_brute_force(input, value));
}

TEST(TestMakeDivisibleByValueBruteForce, simple3) {
    std::vector<int> input{1, 2, 3};
    constexpr int value{3};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, min_size_of_subarray_brute_force(input, value));
}


TEST(TestMakeDivisibleByValueBruteForce, simple4) {
    std::vector<int> input{6, 1, 7, 1, 7};
    constexpr int value{7};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, min_size_of_subarray_brute_force(input, value));
}

TEST(TestMakeDivisibleByValueBruteForce, simple5) {
    std::vector<int> input{6, 1, 7, 1, 7};
    constexpr int value{51};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, min_size_of_subarray_brute_force(input, value));
}


TEST(TestMakeDivisibleByValueBruteForce, complex1) {
    std::vector<int> input{8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2};
    constexpr int value{148};
    constexpr int expected_result{7};
    EXPECT_EQ(expected_result, min_size_of_subarray_brute_force(input, value));
}

TEST(TestMakeDivisibleByValueBruteForce, complex2) {
    std::vector<int> input{3, 4, 79, 65, 11, 1, 44, 4, 12, 53, 21, 52, 52, 37, 86, 58, 37, 17, 5, 61, 74, 85, 18, 71,
                           79, 68, 25, 63, 73, 36, 69, 3, 84, 70, 86, 22, 4, 3, 58, 32, 44, 12, 17, 58, 32, 63};
    constexpr int value{1352};
    constexpr int expected_result{11};
    EXPECT_EQ(expected_result, min_size_of_subarray_brute_force(input, value));
}

TEST(TestMakeDivisibleByValueBruteForce, complex3) {
    std::vector<int> input{5, 25, 7, 25, 1, 29, 16, 7, 7, 30, 29, 2, 14, 33, 25, 4, 7, 37, 15};
    constexpr int value{268};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, min_size_of_subarray_brute_force(input, value));
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TestMakeDivisibleByValue, simple1) {
    std::vector<int> input{3, 1, 4, 2};
    constexpr int value{6};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, min_size_of_subarray(input, value));
}

TEST(TestMakeDivisibleByValue, simple2) {
    std::vector<int> input{6, 3, 5, 2};
    constexpr int value{9};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, min_size_of_subarray(input, value));
}

TEST(TestMakeDivisibleByValue, simple3) {
    std::vector<int> input{1, 2, 3};
    constexpr int value{3};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, min_size_of_subarray(input, value));
}


TEST(TestMakeDivisibleByValue, simple4) {
    std::vector<int> input{6, 1, 7, 1, 7};
    constexpr int value{7};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, min_size_of_subarray(input, value));
}

TEST(TestMakeDivisibleByValue, simple5) {
    std::vector<int> input{6, 1, 7, 1, 7};
    constexpr int value{51};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, min_size_of_subarray(input, value));
}


TEST(TestMakeDivisibleByValue, complex1) {
    std::vector<int> input{8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2};
    constexpr int value{148};
    constexpr int expected_result{7};
    EXPECT_EQ(expected_result, min_size_of_subarray(input, value));
}

TEST(TestMakeDivisibleByValue, complex2) {
    std::vector<int> input{3, 4, 79, 65, 11, 1, 44, 4, 12, 53, 21, 52, 52, 37, 86, 58, 37, 17, 5, 61, 74, 85, 18, 71,
                           79, 68, 25, 63, 73, 36, 69, 3, 84, 70, 86, 22, 4, 3, 58, 32, 44, 12, 17, 58, 32, 63};
    constexpr int value{1352};
    constexpr int expected_result{11};
    EXPECT_EQ(expected_result, min_size_of_subarray(input, value));
}

TEST(TestMakeDivisibleByValue, complex3) {
    std::vector<int> input{5, 25, 7, 25, 1, 29, 16, 7, 7, 30, 29, 2, 14, 33, 25, 4, 7, 37, 15};
    constexpr int value{268};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, min_size_of_subarray(input, value));
}
