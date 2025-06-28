//
// Created by andreas on 28.06.25.
//
#include "gtest/gtest.h"
#include "stacks_and_queues/basic_calculator3.h"


TEST(BasicCalculatorIIITest, SingleNumber) {
    EXPECT_EQ(calculated3("3"), 3);
    EXPECT_EQ(calculated3("0"), 0);
}

TEST(BasicCalculatorIIITest, AdditionAndSubtraction) {
    EXPECT_EQ(calculated3("1 + 2 - 3"), 0);
    EXPECT_EQ(calculated3("10-5+2"), 7);
}

TEST(BasicCalculatorIIITest, MultiplicationAndDivision) {
    EXPECT_EQ(calculated3("3*4"), 12);
    EXPECT_EQ(calculated3("8/2"), 4);
    EXPECT_EQ(calculated3("14-3*2"), 8);
}

TEST(BasicCalculatorIIITest, MixedOperators) {
    EXPECT_EQ(calculated3("2+3*4"), 14);
    EXPECT_EQ(calculated3("100/5+6*2"), 32);
}

TEST(BasicCalculatorIIITest, Parentheses) {
    EXPECT_EQ(calculated3("(1+2)*3"), 9);
    EXPECT_EQ(calculated3("2*(3+4)-5"), 9);
    EXPECT_EQ(calculated3("(2+3)*(5-2)"), 15);
}

TEST(BasicCalculatorIIITest, NestedParentheses) {
    EXPECT_EQ(calculated3("((2+3)*((1+1)+1))"), 15);
    EXPECT_EQ(calculated3("((1+(4+5+2)-3)+(6+8))"), 23);
}

TEST(BasicCalculatorIIITest, Whitespaces) {
    EXPECT_EQ(calculated3(" 3 +   5 /  2 "), 5);  // 5 because 5/2 truncates to 2
}

TEST(BasicCalculatorIIITest, ComplexExpression) {
    EXPECT_EQ(calculated3("(2+6* 3+5- (3*14/7+2)*5)+3"), -12);
}

// Optional: Edge cases
TEST(BasicCalculatorIIITest, LargeNumbers) {
    EXPECT_EQ(calculated3("1000000*2+1"), 2000001);
}