//
// Created by andreas on 28.12.23.
//

#include "gtest/gtest.h"
#include "../number_of_string_decodings.h"

TEST(TestNumberOfStringDecodings, simple1)
{
	const std::string input{"12"};
	constexpr int expected_result{2};
	EXPECT_EQ(expected_result, number_of_decodings_bottom_up(input));
}

TEST(TestNumberOfStringDecodings, simple2)
{
	const std::string input{"226"};
	constexpr int expected_result{3};
	EXPECT_EQ(expected_result, number_of_decodings_bottom_up(input));
}

TEST(TestNumberOfStringDecodings, simple3)
{
	const std::string input{"06"};
	constexpr int expected_result{0};
	EXPECT_EQ(expected_result, number_of_decodings_bottom_up(input));
}

TEST(TestNumberOfStringDecodings, simple4)
{
	const std::string input{"1372189472892"};
	constexpr int expected_result{6};
	EXPECT_EQ(expected_result, number_of_decodings_bottom_up(input));
}

TEST(TestNumberOfStringDecodings, complex1)
{
	const std::string input{"1372189438492384923849237289212127819111"};
	constexpr int expected_result{2304};
	EXPECT_EQ(expected_result, number_of_decodings_bottom_up(input));
}
