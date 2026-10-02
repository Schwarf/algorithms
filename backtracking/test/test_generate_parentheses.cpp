//
// Created by andreas on 02.10.26.
//

#include "generate_parentheses.h"
#include "gtest/gtest.h"

#include <string>
#include <vector>

namespace
{
bool is_well_formed(const std::string& parentheses)
{
    int balance{};
    for (const auto character : parentheses)
    {
        if (character == '(')
            ++balance;
        else if (character == ')')
            --balance;
        else
            return false;

        if (balance < 0)
            return false;
    }

    return balance == 0;
}
}

TEST(GenerateParentheses, zeroPairs)
{
    const std::vector<std::string> expected_result{""};
    EXPECT_EQ(expected_result, generate_parentheses(0));
}

TEST(GenerateParentheses, onePair)
{
    const std::vector<std::string> expected_result{"()"};
    EXPECT_EQ(expected_result, generate_parentheses(1));
}

TEST(GenerateParentheses, twoPairs)
{
    const std::vector<std::string> expected_result{"(())", "()()"};
    EXPECT_EQ(expected_result, generate_parentheses(2));
}

TEST(GenerateParentheses, threePairs)
{
    const std::vector<std::string> expected_result{"((()))", "(()())", "(())()", "()(())", "()()()"};
    EXPECT_EQ(expected_result, generate_parentheses(3));
}

TEST(GenerateParentheses, fourPairsProducesAllWellFormedCombinations)
{
    const auto result = generate_parentheses(4);

    EXPECT_EQ(14, result.size());
    for (const auto& parentheses : result)
    {
        EXPECT_EQ(8, parentheses.size());
        EXPECT_TRUE(is_well_formed(parentheses)) << parentheses;
    }
}
