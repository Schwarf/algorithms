//
// Created by andreas on 14.03.25.
//
#include "./../minimal_data_costs.h"
#include "gtest/gtest.h"

TEST(TestMinimalDataCosts, simple1)
{
    std::string input{"abc?abc?"};
    const std::string expected_result{"abcdabce"};
    EXPECT_EQ(minimal_data_costs(input), expected_result);
}

TEST(TestMinimalDataCosts, simple2)
{
    std::string input{"abcdef?ghijklmnopqrst?uvwxyz?"};
    const std::string expected_result{"abcdefaghijklmnopqrstbuvwxyzc"};
    EXPECT_EQ(minimal_data_costs(input), expected_result);
}

TEST(TestMinimalDataCosts, simple3)
{
    std::string input{"a?b??c"};
    const std::string expected_result{"adbefc"};
    EXPECT_EQ(minimal_data_costs(input), expected_result);
}
