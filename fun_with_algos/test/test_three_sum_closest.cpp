//
// Created by andreas on 14.05.25.
//
#include "./../three_sum_closest.h"
#include "gtest/gtest.h"

TEST(TestThreeSumClosest, simple1)
{
    std::vector<int> input{-1, 2, 1, 4};
    constexpr int target{1};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, three_sum_closest(input, target));
}

TEST(TestThreeSumClosest, simple2)
{
    std::vector<int> input{0, 0, 0};
    constexpr int target{1};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, three_sum_closest(input, target));
}

TEST(TestThreeSumClosest, medium1)
{
    std::vector<int> input{-84, 92, 26, 19, -7, 9, 42, -51, 8, 30, -100, -13, -38};
    constexpr int target{78};
    constexpr int expected_result{77};
    EXPECT_EQ(expected_result, three_sum_closest(input, target));
}

TEST(TestThreeSumClosest, complex1)
{
    std::vector<int> input{
        40, -53, 36, 89, -38, -51, 80, 11, -10, 76, -30, 46, -39, -15, 4, 72, 83, -25, 33, -69, -73, -100, -23, -37,
        -13, -62, -26, -54, 36, -84, -65, -51, 11, 98, -21, 49, 51, 78, -58, -40, 95, -81, 41, -17, -70, 83, -88, -14,
        -75, -10, -44, -21, 6, 68, -81, -1, 41, -61, -82, -24, 45, 19, 6, -98, 11, 9, -66, 50, -97, -2, 58, 17, 51, -13,
        88, -16, -77, 31, 35, 98, -2, 0, -70, 6, -34, -8, 78, 22, -1, -93, -39, -88, -77, -65, 80, 91, 35, -15, 7, -37,
        -96, 65, 3, 33, -22, 60, 1, 76, -32, 22
    };
    constexpr int target{292};
    constexpr int expected_result{291};
    EXPECT_EQ(expected_result, three_sum_closest(input, target));
}
