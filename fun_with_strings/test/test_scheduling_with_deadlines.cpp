//
// Created by andreas on 18.12.25.
//
#include "./../scheduling_with_deadlines.h"
#include "gtest/gtest.h"


TEST(TestSchedulingWithDeadlines, simple1)
{
    std::vector<std::unordered_map<std::string, int>> jobs{};

    constexpr int expected_result = 0;
    EXPECT_EQ(optimal_freelancing(jobs), expected_result);
}

TEST(TestSchedulingWithDeadlines, simple2)
{
    std::vector<std::unordered_map<std::string, int>> jobs{
            {{"deadline", 1,},{"payment", 1} },
            {{"deadline", 1}, {"payment", 2} }
    };

    constexpr int expected_result = 2;
    EXPECT_EQ(optimal_freelancing(jobs), expected_result);
}