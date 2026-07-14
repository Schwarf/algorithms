#include <gtest/gtest.h>

#include "max_consecutive_ones.h"

TEST(TestMaxConsecutiveOnes, finds_longest_window_with_at_most_k_zeros)
{
    const std::vector<int> input{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

    EXPECT_EQ(6, max_consecutive_ones(input, 2));
}

TEST(TestMaxConsecutiveOnes, empty_input)
{
    const std::vector<int> input{};

    EXPECT_EQ(0, max_consecutive_ones(input, 2));
}

TEST(TestMaxConsecutiveOnes, k_is_zero)
{
    const std::vector<int> input{1, 1, 0, 1, 1, 1, 0, 1};

    EXPECT_EQ(3, max_consecutive_ones(input, 0));
}

TEST(TestMaxConsecutiveOnes, all_ones)
{
    const std::vector<int> input{1, 1, 1, 1};

    EXPECT_EQ(4, max_consecutive_ones(input, 1));
}

TEST(TestMaxConsecutiveOnes, all_zeros_with_no_flips)
{
    const std::vector<int> input{0, 0, 0};

    EXPECT_EQ(0, max_consecutive_ones(input, 0));
}

TEST(TestMaxConsecutiveOnes, all_zeros_with_partial_flips)
{
    const std::vector<int> input{0, 0, 0, 0};

    EXPECT_EQ(2, max_consecutive_ones(input, 2));
}

TEST(TestMaxConsecutiveOnes, k_covers_all_zeros)
{
    const std::vector<int> input{0, 1, 0, 1, 1, 0};

    EXPECT_EQ(6, max_consecutive_ones(input, 3));
}

TEST(TestMaxConsecutiveOnes, k_larger_than_number_of_zeros)
{
    const std::vector<int> input{1, 0, 1};

    EXPECT_EQ(3, max_consecutive_ones(input, 5));
}

TEST(TestMaxConsecutiveOnes, single_one)
{
    const std::vector<int> input{1};

    EXPECT_EQ(1, max_consecutive_ones(input, 0));
}

TEST(TestMaxConsecutiveOnes, single_zero_without_flip)
{
    const std::vector<int> input{0};

    EXPECT_EQ(0, max_consecutive_ones(input, 0));
}

TEST(TestMaxConsecutiveOnes, single_zero_with_flip)
{
    const std::vector<int> input{0};

    EXPECT_EQ(1, max_consecutive_ones(input, 1));
}

TEST(TestMaxConsecutiveOnes, best_window_starts_at_left_boundary)
{
    const std::vector<int> input{1, 1, 0, 1, 0, 0};

    EXPECT_EQ(4, max_consecutive_ones(input, 1));
}

TEST(TestMaxConsecutiveOnes, best_window_ends_at_right_boundary)
{
    const std::vector<int> input{0, 0, 1, 0, 1, 1};

    EXPECT_EQ(4, max_consecutive_ones(input, 1));
}
