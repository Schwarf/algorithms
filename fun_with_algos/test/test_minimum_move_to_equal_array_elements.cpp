//
// Created by andreas on 01.11.26.
//
#include "./../minimum_move_to_equal_array_elements.h"
#include "gtest/gtest.h"

TEST(MinimumMovesToEqualArrayElements, ComputesMovesForIncreasingValues)
{
    const std::vector<int> input{1, 2, 3};

    EXPECT_EQ(minimum_moves(input), 3);
}

TEST(MinimumMovesToEqualArrayElements, ReturnsZeroWhenAllValuesAreEqual)
{
    const std::vector<int> input{5, 5, 5, 5};

    EXPECT_EQ(minimum_moves(input), 0);
}

TEST(MinimumMovesToEqualArrayElements, ReturnsZeroForSingleValue)
{
    const std::vector<int> input{42};

    EXPECT_EQ(minimum_moves(input), 0);
}

TEST(MinimumMovesToEqualArrayElements, HandlesUnsortedValuesAndDuplicateMinimum)
{
    const std::vector<int> input{7, 2, 9, 2};

    EXPECT_EQ(minimum_moves(input), 12);
}

TEST(MinimumMovesToEqualArrayElements, HandlesNegativeValues)
{
    const std::vector<int> input{-1, -4, 2};

    EXPECT_EQ(minimum_moves(input), 9);
}
