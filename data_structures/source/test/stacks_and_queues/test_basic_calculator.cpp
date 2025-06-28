//
// Created by andreas on 28.06.25.
//
#include "gtest/gtest.h"
#include "stacks_and_queues/basic_calculator.h"

TEST(BasicCalculatorTest, HandlesSimpleAddition)
{
    EXPECT_EQ(calculate("1+1"), 2);
}

TEST(BasicCalculatorTest, HandlesSpacesAndSubtraction)
{
    EXPECT_EQ(calculate(" 2-1 + 2 "), 3);
}

TEST(BasicCalculatorTest, HandlesParentheses)
{
    EXPECT_EQ(calculate("(1+(4+5+2)-3)+(6+8)"), 23);
}

TEST(BasicCalculatorTest, HandlesNestedParentheses)
{
    EXPECT_EQ(calculate("((1))"), 1);
}

TEST(BasicCalculatorTest, HandlesLeadingMinus)
{
    EXPECT_EQ(calculate("- (3 + (2 - 1))"), -4);
}

TEST(BasicCalculatorTest, HandlesLargeNumber)
{
    EXPECT_EQ(calculate("2147483647"), 2147483647);
}
