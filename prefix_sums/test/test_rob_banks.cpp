//
// Created by andreas on 15.04.25.
//
#include "gtest/gtest.h"
#include "./../rob_banks.h"

TEST(TestRobBanks, simple1)
{
    std::vector<int> security{5, 3, 3, 3, 5, 6, 2};
    constexpr int time{2};
    std::vector<int> expected_result{2, 3};
    EXPECT_EQ(expected_result, rob_banks(security, time));
}

TEST(TestRobBanks, simple2)
{
    std::vector<int> security{1, 1, 1, 1, 1};
    constexpr int time{0};
    std::vector<int> expected_result{0, 1, 2, 3, 4};
    EXPECT_EQ(expected_result, rob_banks(security, time));
}

TEST(TestRobBanks, simple3)
{
    std::vector<int> security{1, 2, 3, 4, 5};
    constexpr int time{1};
    std::vector<int> expected_result{};
    EXPECT_EQ(expected_result, rob_banks(security, time));
}

TEST(TestRobBanks, complex1)
{
    std::vector<int> security{
        77, 9, 111, 138, 139, 183, 112, 127, 38, 123, 198, 86, 163, 50, 140, 106, 99, 140, 152, 176, 124, 181, 14, 113,
        53, 186, 76, 165, 32, 26, 137, 4, 186, 193, 130, 157, 173, 52, 27, 101, 154, 129, 34, 200, 51, 184, 127, 147,
        197, 151, 190, 95, 62, 182, 77, 34, 174, 162, 7, 84, 105, 103, 128
    };
    constexpr int time{2};
    std::vector<int> expected_result{16, 38, 58};
    EXPECT_EQ(expected_result, rob_banks(security, time));
}
