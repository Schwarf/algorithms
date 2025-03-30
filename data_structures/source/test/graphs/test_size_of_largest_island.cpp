//
// Created by andreas on 15.07.22.
//
#include "gtest/gtest.h"
#include "graphs/size_of_largest_island.h"
#include <vector>

class SetupIslands : public testing::Test
{
protected:
    std::vector<std::vector<int>> earth1{
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };

    int answer1{6};

    std::vector<std::vector<int>> earth2{
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1}
    };

    int answer2{10};

    std::vector<std::vector<int>> earth3{{0, 0, 0}};
    int answer3{0};
};

TEST_F(SetupIslands, test_iterative_approach_earth1)
{
    auto result = size_of_largest_island(earth1);
    EXPECT_EQ(result, answer1);
}

TEST_F(SetupIslands, test_iterative_approach_earth2)
{
    auto result = size_of_largest_island(earth2);
    EXPECT_EQ(result, answer2);
}

TEST_F(SetupIslands, test_iterative_approach_earth3)
{
    auto result = size_of_largest_island(earth3);
    EXPECT_EQ(result, answer3);
}


TEST_F(SetupIslands, test_recursive_approach_earth1)
{
    auto result = size_of_largest_island_recursive(earth1);
    EXPECT_EQ(result, answer1);
}

TEST_F(SetupIslands, test_recursive_approach_earth2)
{
    auto result = size_of_largest_island_recursive(earth2);
    EXPECT_EQ(result, answer2);
}

TEST_F(SetupIslands, test_recursive_approach_earth3)
{
    auto result = size_of_largest_island_recursive(earth3);
    EXPECT_EQ(result, answer3);
}
