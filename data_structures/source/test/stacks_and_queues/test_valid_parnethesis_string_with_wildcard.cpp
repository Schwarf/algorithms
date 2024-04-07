//
// Created by andreas on 07.04.24.
//
#include "gtest/gtest.h"
#include "stacks_and_queues/valid_parenthesis_string_with_wildcard.h"

TEST(TestValidParenthesisStringWithWildcard, simple1)
{
	std::string input{"()"};
	EXPECT_TRUE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, simple2)
{
	std::string input{"(*)"};
	EXPECT_TRUE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, simple3)
{
	std::string input{"(*))"};
	EXPECT_TRUE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, simple4)
{
	std::string input{"("};
	EXPECT_FALSE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, simple5)
{
	std::string input{")"};
	EXPECT_FALSE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, simple6)
{
	std::string input{"**"};
	EXPECT_TRUE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, simple7)
{
	std::string input{"*(()"};
	EXPECT_FALSE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, simple8)
{
	std::string input{"**()"};
	EXPECT_TRUE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, simple9)
{
	std::string input{"**(*)(*"};
	EXPECT_TRUE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, simple10)
{
	std::string input{"**(*)(*("};
	EXPECT_FALSE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, complex1)
{
	std::string
		input{"(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"};
	EXPECT_FALSE(is_parenthesis_string_with_wildcard_valid(input));
}

TEST(TestValidParenthesisStringWithWildcard, complex2)
{
	std::string
		input{"((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"};
	EXPECT_TRUE(is_parenthesis_string_with_wildcard_valid(input));
}