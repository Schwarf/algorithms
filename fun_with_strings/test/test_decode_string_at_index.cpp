//
// Created by andreas on 27.09.23.
//
#include "gtest/gtest.h"
#include "./../decode_string_at_index.h"

TEST(TestDecodeStringAtIndex, simple1)
{
	const std::string input{"bcabc"};
	constexpr int k{3};
	const std::string expected_result{"a"};
	EXPECT_EQ(decode_at_index(input, k), expected_result );
}

TEST(TestDecodeStringAtIndex, simple2)
{
	const std::string input{"abab3d"};
	constexpr int k{5};
	const std::string expected_result{"a"};
	EXPECT_EQ(decode_at_index(input, k), expected_result );
}


TEST(TestDecodeStringAtIndex, simple3)
{
	const std::string input{"jh32"};
	constexpr int k{12};
	const std::string expected_result{"h"};
	EXPECT_EQ(decode_at_index(input, k), expected_result );
}

TEST(TestDecodeStringAtIndex, medium1)
{
	const std::string input{"meat2grind3hallo7"};
	constexpr int k{57};
	const std::string expected_result{"d"};
	EXPECT_EQ(decode_at_index(input, k), expected_result );
}

TEST(TestDecodeStringAtIndex, complex1)
{
	const std::string input{"smaug3dwarves99elvess876"};
	constexpr int k{1178};
	const std::string expected_result{"m"};
	EXPECT_EQ(decode_at_index(input, k), expected_result );
}
