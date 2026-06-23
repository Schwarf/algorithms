//
// Created by andreas on 23.06.26.
//
#include <vector>

#include <gtest/gtest.h>

#include "target_sum_ways.h"

// Include the header that declares target_sum_ways().
// #include "backtracking/target_sum.h"

TEST(TargetSumWaysTest, ReturnsFiveForLeetCodeExample)
{
    std::vector<int> nums{1, 1, 1, 1, 1};

    EXPECT_EQ(target_sum_ways(nums, 3), 5);
}

TEST(TargetSumWaysTest, HandlesSinglePositiveValue)
{
    std::vector<int> nums{5};

    EXPECT_EQ(target_sum_ways(nums, 5), 1);   // +5
}

TEST(TargetSumWaysTest, HandlesSingleNegativeTarget)
{
    std::vector<int> nums{5};

    EXPECT_EQ(target_sum_ways(nums, -5), 1);  // -5
}

TEST(TargetSumWaysTest, ReturnsZeroWhenTargetCannotBeReached)
{
    std::vector<int> nums{1, 2, 3};

    EXPECT_EQ(target_sum_ways(nums, 10), 0);
}

TEST(TargetSumWaysTest, CountsDifferentSignAssignmentsSeparately)
{
    std::vector<int> nums{1, 2};

    // -1 + 2 = 1
    EXPECT_EQ(target_sum_ways(nums, 1), 1);
}

TEST(TargetSumWaysTest, HandlesSeveralWaysForTargetZero)
{
    std::vector<int> nums{1, 1, 2, 3};

    EXPECT_EQ(target_sum_ways(nums, 0), 0);
}

TEST(TargetSumWaysTest, CorrectlyCountsZeroValues)
{
    std::vector<int> nums{0};

    // +0 and -0 are distinct expressions.
    EXPECT_EQ(target_sum_ways(nums, 0), 2);
}

TEST(TargetSumWaysTest, EachZeroDoublesTheNumberOfExpressions)
{
    std::vector<int> nums{0, 0, 0, 0, 0};

    // Every element has two sign choices, all evaluate to zero.
    EXPECT_EQ(target_sum_ways(nums, 0), 32);
}

TEST(TargetSumWaysTest, HandlesZerosTogetherWithNonZeroValues)
{
    std::vector<int> nums{0, 0, 1};

    // The 1 must receive '+', while each zero has two independent signs.
    EXPECT_EQ(target_sum_ways(nums, 1), 4);
}

TEST(TargetSumWaysTest, HandlesNegativeTargetWithSeveralValues)
{
    std::vector<int> nums{1, 2, 1};

    // -1 -2 +1 = -2
    // +1 -2 -1 = -2
    EXPECT_EQ(target_sum_ways(nums, -2), 2);
}

TEST(TargetSumWaysTest, HandlesEmptyInputForTargetZero)
{
    std::vector<int> nums;

    // The empty sign assignment evaluates to zero.
    EXPECT_EQ(target_sum_ways(nums, 0), 1);
}

TEST(TargetSumWaysTest, HandlesEmptyInputForNonZeroTarget)
{
    std::vector<int> nums;

    EXPECT_EQ(target_sum_ways(nums, 1), 0);
}

TEST(TargetSumWaysTest, DoesNotModifyInput)
{
    std::vector<int> nums{1, 1, 1, 1, 1};
    const std::vector<int> expected_nums{1, 1, 1, 1, 1};

    EXPECT_EQ(target_sum_ways(nums, 3), 5);
    EXPECT_EQ(nums, expected_nums);
}