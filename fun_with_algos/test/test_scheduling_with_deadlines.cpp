//
// Created by andreas on 18.12.25.
//
#include "../scheduling_with_deadlines.h"
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

TEST(TestSchedulingWithDeadlines, simple3)
{
    std::vector<std::unordered_map<std::string, int>> jobs{
        { {"deadline", 1}, {"payment", 1} }
    };

    constexpr int expected_result = 1;
    EXPECT_EQ(optimal_freelancing(jobs), expected_result);
}

TEST(TestSchedulingWithDeadlines, simple4)
{
    std::vector<std::unordered_map<std::string, int>> jobs{
        { {"deadline", 2}, {"payment", 1} },
        { {"deadline", 1}, {"payment", 4} },
        { {"deadline", 3}, {"payment", 2} },
        { {"deadline", 1}, {"payment", 3} },
        { {"deadline", 4}, {"payment", 3} },
        { {"deadline", 4}, {"payment", 2} },
        { {"deadline", 4}, {"payment", 1} },
        { {"deadline", 5}, {"payment", 4} },
        { {"deadline", 8}, {"payment", 1} }
    };

    constexpr int expected_result = 16;
    EXPECT_EQ(optimal_freelancing(jobs), expected_result);
}

TEST(TestSchedulingWithDeadlines, simple5)
{
    std::vector<std::unordered_map<std::string, int>> jobs{
        { {"deadline", 8}, {"payment", 3} },
        { {"deadline", 1}, {"payment", 1} },
        { {"deadline", 1}, {"payment", 2} }
    };

    constexpr int expected_result = 5;
    EXPECT_EQ(optimal_freelancing(jobs), expected_result);
}