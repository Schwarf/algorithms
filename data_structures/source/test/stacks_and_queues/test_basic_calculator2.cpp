//
// Created by andreas on 28.06.25.
//
#include "gtest/gtest.h"
#include "stacks_and_queues/basic_calculator2.h"


TEST(BasicCalculatorIITest, HandlesSingleNumber) {
    EXPECT_EQ(calculated2("42"), 42);
}

TEST(BasicCalculatorIITest, HandlesAdditionAndSubtraction) {
    EXPECT_EQ(calculated2("2-1+2"), 3);
}

TEST(BasicCalculatorIITest, HandlesMultiplication) {
    EXPECT_EQ(calculated2("2*3*4"), 24);
}

TEST(BasicCalculatorIITest, HandlesDivisionTruncation) {
    EXPECT_EQ(calculated2("3/2"), 1);
    EXPECT_EQ(calculated2("14-3/2"), 13);
}

TEST(BasicCalculatorIITest, HandlesMixedOperators) {
    EXPECT_EQ(calculated2("3+2*2"), 7);
    EXPECT_EQ(calculated2(" 3+5 / 2 "), 5);
}

TEST(BasicCalculatorIITest, HandlesWhitespace) {
    EXPECT_EQ(calculated2("  12* 3 -  4 /2 "), 34);
}

TEST(BasicCalculatorIITest, HandlesNegativeResults) {
    EXPECT_EQ(calculated2("1-1+1-3"), -2);
}