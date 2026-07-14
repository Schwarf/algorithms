#include <gtest/gtest.h>

#include "max_sum_subarray_size_k.h"

TEST(TestMaxSumSubarraySizeK, simple1)
{
    std::vector<int> input{2, 1, 5, 1, 3, 2};

    EXPECT_EQ(9, max_sum_subarray_size_k(input, 3));
}

TEST(TestMaxSumSubarraySizeK, simple2)
{
    std::vector<int> input{2, 3, 4, 1, 5};

    EXPECT_EQ(7, max_sum_subarray_size_k(input, 2));
}

TEST(TestMaxSumSubarraySizeK, k_is_one)
{
    std::vector<int> input{-8, -3, -5, -2};

    EXPECT_EQ(-2, max_sum_subarray_size_k(input, 1));
}

TEST(TestMaxSumSubarraySizeK, k_is_input_size)
{
    std::vector<int> input{4, -1, 2, 7};

    EXPECT_EQ(12, max_sum_subarray_size_k(input, 4));
}

TEST(TestMaxSumSubarraySizeK, handles_all_negative_values)
{
    std::vector<int> input{-5, -2, -3, -4};

    EXPECT_EQ(-5, max_sum_subarray_size_k(input, 2));
}

TEST(TestMaxSumSubarraySizeK, handles_mixed_values)
{
    std::vector<int> input{4, -1, -2, 10, -3, 4};

    EXPECT_EQ(11, max_sum_subarray_size_k(input, 4));
}

TEST(TestMaxSumSubarraySizeK, empty_input)
{
    std::vector<int> input{};

    EXPECT_EQ(0, max_sum_subarray_size_k(input, 3));
}

TEST(TestMaxSumSubarraySizeK, k_larger_than_input)
{
    std::vector<int> input{1, 2};

    EXPECT_EQ(0, max_sum_subarray_size_k(input, 3));
}

TEST(TestMaxSumSubarraySizeK, k_is_zero)
{
    std::vector<int> input{1, 2, 3};

    EXPECT_EQ(0, max_sum_subarray_size_k(input, 0));
}

TEST(TestMaxSumSubarraySizeK, k_is_negative)
{
    std::vector<int> input{1, 2, 3};

    EXPECT_EQ(0, max_sum_subarray_size_k(input, -1));
}
