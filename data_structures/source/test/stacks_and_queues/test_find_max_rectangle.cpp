//
// Created by andreas on 13.04.24.
//
#include "gtest/gtest.h"
#include "stacks_and_queues/find_max_rectangle.h"


TEST(TestFinMaxRectangle, simple1)
{
    std::vector<std::vector<char>> input{{'0'}};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, find_maximal_rectangle(input));
}

TEST(TestFinMaxRectangle, simple2)
{
    std::vector<std::vector<char>> input{{'1'}};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, find_maximal_rectangle(input));
}

TEST(TestFinMaxRectangle, simple3)
{
    std::vector<std::vector<char>> input{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, find_maximal_rectangle(input));
}

TEST(TestFinMaxRectangle, simple4)
{
    std::vector<std::vector<char>> input{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '0', '1'},
        {'1', '0', '0', '1', '0'}
    };
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, find_maximal_rectangle(input));
}


TEST(TestFinMaxRectangle, simple5)
{
    std::vector<std::vector<char>> input{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'0', '1', '0', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, find_maximal_rectangle(input));
}


TEST(TestFinMaxRectangle, simple6)
{
    std::vector<std::vector<char>> input{
        {'0', '0', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '1', '1'},
        {'0', '1', '1', '1'},
        {'0', '1', '1', '1'},
        {'1', '1', '1', '1'}
    };
    constexpr int expected_result{9};
    EXPECT_EQ(expected_result, find_maximal_rectangle(input));
}


TEST(TestFinMaxRectangle, simple7)
{
    std::vector<std::vector<char>> input{
        {'0', '1', '1', '1'},
        {'0', '1', '1', '1'},
        {'0', '1', '1', '1'},
        {'0', '1', '1', '1'},
        {'0', '1', '1', '1'},
        {'0', '1', '1', '1'},
        {'1', '1', '1', '1'}
    };
    constexpr int expected_result{21};
    EXPECT_EQ(expected_result, find_maximal_rectangle(input));
}
