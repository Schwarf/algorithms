//
// Created by andreas on 22.11.22.
//
#include "gtest/gtest.h"
#include "perfect_squares.h"


TEST(TestPerfectSquares, simple_bottom_up1)
{
    constexpr int target{1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed(target));
}


TEST(TestPerfectSquares, simple_bottom_up2)
{
    constexpr int target{12};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed(target));
}

TEST(TestPerfectSquares, simple_bottom_up3)
{
    constexpr int target{13};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed(target));
}

TEST(TestPerfectSquares, complex_bottom_up1)
{
    constexpr int target{1791};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed(target));
}

TEST(TestPerfectSquares, complex_bottom_up2)
{
    constexpr int target{9773};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed(target));
}


TEST(TestPerfectSquares, simple_recursive1)
{
    constexpr int target{1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed_recursive(target));
}


TEST(TestPerfectSquares, simple_recursive2)
{
    constexpr int target{12};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed_recursive(target));
}

TEST(TestPerfectSquares, simple_recursive3)
{
    constexpr int target{13};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed_recursive(target));
}

TEST(TestPerfectSquares, simple_top_down1)
{
    constexpr int target{1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed_top_down(target));
}


TEST(TestPerfectSquares, simple_top_down2)
{
    constexpr int target{12};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed_top_down(target));
}

TEST(TestPerfectSquares, simple_top_down3)
{
    constexpr int target{13};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed_top_down(target));
}

TEST(TestPerfectSquares, complex_top_down1)
{
    constexpr int target{1791};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed_top_down(target));
}

TEST(TestPerfectSquares, complex_top_down2)
{
    constexpr int target{9773};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, number_of_perfect_square_summands_needed_top_down(target));
}
