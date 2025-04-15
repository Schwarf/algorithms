//
// Created by andreas on 16.03.24.
//
#include "gtest/gtest.h"
#include "contiguous_array.h"

TEST(TestContiguousArray, simple1)
{
    const std::vector<int> input{0, 1};
    constexpr int expected_answer{2};
    EXPECT_EQ(find_max_contiguous_array(input), expected_answer);
}

TEST(TestContiguousArray, simple2)
{
    const std::vector<int> input{0, 1, 1};
    constexpr int expected_answer{2};
    EXPECT_EQ(find_max_contiguous_array(input), expected_answer);
}

TEST(TestContiguousArray, simple3)
{
    const std::vector<int> input{0, 1, 0};
    constexpr int expected_answer{2};
    EXPECT_EQ(find_max_contiguous_array(input), expected_answer);
}

TEST(TestContiguousArray, simple4)
{
    const std::vector<int> input{0, 1, 1, 1, 1, 1, 0};
    constexpr int expected_answer{2};
    EXPECT_EQ(find_max_contiguous_array(input), expected_answer);
}

TEST(TestContiguousArray, simple5)
{
    const std::vector<int> input{1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
    constexpr int expected_answer{8};
    EXPECT_EQ(find_max_contiguous_array(input), expected_answer);
}

TEST(TestContiguousArray, simple6)
{
    const std::vector<int> input{0, 0, 1, 1, 0, 0};
    constexpr int expected_answer{4};
    EXPECT_EQ(find_max_contiguous_array(input), expected_answer);
}

TEST(TestContiguousArray, simple7)
{
    const std::vector<int> input{1, 1, 1, 0, 0};
    constexpr int expected_answer{4};
    EXPECT_EQ(find_max_contiguous_array(input), expected_answer);
}
