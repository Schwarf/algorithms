//
// Created by andreas on 06.10.23.
//
#include "gtest/gtest.h"
#include "maximize_product_from_given_target.h"

TEST(TestMaximizeProductFromGivenTarget, top_down1)
{
    constexpr unsigned int target{2};
    constexpr unsigned int expected_result{1};
    EXPECT_EQ(maximize_product_top_down(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, top_down2)
{
    constexpr unsigned int target{10};
    constexpr unsigned int expected_result{36};
    EXPECT_EQ(maximize_product_top_down(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, top_down3)
{
    constexpr unsigned int target{35};
    constexpr unsigned int expected_result{354294};
    EXPECT_EQ(maximize_product_top_down(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, top_down4)
{
    constexpr unsigned int target{48};
    constexpr unsigned int expected_result{43046721};
    EXPECT_EQ(maximize_product_top_down(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, bottom_up1)
{
    constexpr unsigned int target{2};
    constexpr unsigned int expected_result{1};
    EXPECT_EQ(maximize_product_bottom_up(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, bottom_up2)
{
    constexpr unsigned int target{10};
    constexpr unsigned int expected_result{36};
    EXPECT_EQ(maximize_product_bottom_up(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, bottom_up3)
{
    constexpr unsigned int target{35};
    constexpr unsigned int expected_result{354294};
    EXPECT_EQ(maximize_product_bottom_up(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, bottom_up4)
{
    constexpr unsigned int target{48};
    constexpr unsigned int expected_result{43046721};
    EXPECT_EQ(maximize_product_bottom_up(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, math1)
{
    constexpr unsigned int target{2};
    constexpr unsigned int expected_result{1};
    EXPECT_EQ(maximize_product_math(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, math2)
{
    constexpr unsigned int target{10};
    constexpr unsigned int expected_result{36};
    EXPECT_EQ(maximize_product_math(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, math3)
{
    constexpr unsigned int target{35};
    constexpr unsigned int expected_result{354294};
    EXPECT_EQ(maximize_product_math(target), expected_result);
}

TEST(TestMaximizeProductFromGivenTarget, math4)
{
    constexpr unsigned int target{48};
    constexpr unsigned int expected_result{43046721};
    EXPECT_EQ(maximize_product_math(target), expected_result);
}
