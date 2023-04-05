//
// Created by andreas on 05.04.23.
//
#include "gtest/gtest.h"
#include "basic_bit_operations.h"

TEST(is_bit_position_valid, is_valid1)
{
	int bit_position{};
	while (bit_position < 32) {
		EXPECT_NO_THROW(is_valid_bit_position<uint32_t>(bit_position++));
	}
}

TEST(is_bit_position_valid, is_valid2)
{
	int bit_position{};
	while (bit_position < 16) {
		EXPECT_NO_THROW(is_valid_bit_position<uint16_t>(bit_position++));
	}
}

TEST(is_bit_position_valid, is_valid3)
{
	int bit_position{};
	while (bit_position < 15) {
		EXPECT_NO_THROW(is_valid_bit_position<int16_t>(bit_position++));
	}
}


TEST(is_bit_position_valid, is_valid4)
{
	int bit_position{};
	while (bit_position < 63) {
		EXPECT_NO_THROW(is_valid_bit_position<int64_t>(bit_position++));
	}
}


TEST(is_bit_position_valid, is_invalid1)
{
	constexpr int bit_position{65};
	constexpr int maximum_bit_position{63};
	std::string expected_message
		{"Bit position must be greater than 0 and smaller than " + std::to_string(maximum_bit_position) + "!"};
	try {
		is_valid_bit_position<int64_t>(bit_position);
		FAIL() << "Invalid bit position";
	}
	catch (std::out_of_range const &err) {
		EXPECT_EQ(err.what(), expected_message);
	}
}


TEST(is_bit_position_valid, is_invalid2)
{
	constexpr int bit_position{-1};
	constexpr int maximum_bit_position{63};
	std::string expected_message
		{"Bit position must be greater than 0 and smaller than " + std::to_string(maximum_bit_position) + "!"};
	try {
		is_valid_bit_position<int64_t>(bit_position);
		FAIL() << "Invalid bit position";
	}
	catch (std::out_of_range const &err) {
		EXPECT_EQ(err.what(), expected_message);
	}
}


TEST(is_bit_position_valid, is_invalid3)
{
	constexpr int bit_position{17};
	std::string expected_message
		{"Provided bit position " + std::to_string(bit_position) + " overflows in provided type !"};
	try {
		is_valid_bit_position<uint16_t>(bit_position);
		FAIL() << "Invalid bit position";
	}
	catch (std::out_of_range const &err) {
		EXPECT_EQ(err.what(), expected_message);
	}
}

TEST(has_bit, sample1)
{
	constexpr int input{17};
	std::vector<bool> expected_bit_positions(31, false);
	expected_bit_positions[0] = true;
	expected_bit_positions[4] = true;
	constexpr int maximum_bit{31};
	for(int i{}; i < maximum_bit; ++i)
	{
		if(expected_bit_positions[i])
			EXPECT_TRUE(has_bit(input, i));
		else
			EXPECT_FALSE(has_bit(input, i));
	}
}

TEST(has_bit, zero)
{
	constexpr int input{0};
	constexpr int maximum_bit{31};
	for(int i{}; i < maximum_bit; ++i)
			EXPECT_FALSE(has_bit(input, i));
}

TEST(has_bit, all)
{
	constexpr int maximum_bit = 63;
	uint64_t input{1};
	input <<= maximum_bit;
	input--;
	input += uint64_t{1} << maximum_bit;
	for(int i{}; i < maximum_bit; ++i)
		EXPECT_TRUE(has_bit(input, i));
}

TEST(set_bit, sample1)
{
	int input{17};
	constexpr int bit_to_set{19};
	const auto expected_result = (1 << 19) + 17;
	EXPECT_FALSE(has_bit(input, bit_to_set));
	set_bit(input, bit_to_set);
	EXPECT_TRUE(has_bit(input, bit_to_set));
	EXPECT_EQ(expected_result, input);
}

TEST(set_bit, all_bits)
{
	uint32_t input{0};
	for(int i{}; i < 32; ++i)
	{
		EXPECT_FALSE(has_bit(input, i));
		set_bit(input, i);
		EXPECT_TRUE(has_bit(input, i));
	}
	EXPECT_EQ(input, std::numeric_limits<uint32_t>::max());
}


TEST(clear_bit, sample1)
{
	constexpr int bit1{3};
	constexpr int bit2{17};
	int input = (1<< bit1) + (1<< bit2);
	constexpr int bit_to_clear1{4};
	constexpr int bit_to_clear2{bit2};
	const auto expected_result1 = input;
	const auto expected_result2 = (1 << bit1);
	EXPECT_TRUE(has_bit(input, bit1));
	EXPECT_TRUE(has_bit(input, bit2));
	clear_bit(input, bit_to_clear1);
	EXPECT_EQ(expected_result1, input);
	EXPECT_TRUE(has_bit(input, bit1));
	EXPECT_TRUE(has_bit(input, bit2));

	clear_bit(input, bit_to_clear2);
	EXPECT_EQ(expected_result2, input);
	EXPECT_TRUE(has_bit(input, bit1));
	EXPECT_FALSE(has_bit(input, bit2));
}

TEST(clear_bit, sample2)
{
	constexpr int bit1{25};
	int input = (1<< bit1) -1;
	for(int i{bit1-1}; i >-1; i--)
	{
		EXPECT_TRUE(has_bit(input,i));
		clear_bit(input, i);
		EXPECT_FALSE(has_bit(input,i));
	}
}


TEST(clear_most_siginificant_bits_until_position, sample1)
{
	constexpr int bit1{18};
	int input = (1<< bit1) -1;
	constexpr int clear_most_significant_bits{11};
	for(int i{}; i < bit1; ++i)
		EXPECT_TRUE(has_bit(input, i));

	clear_most_significant_bits_until_position(input, clear_most_significant_bits);
	for(int i{}; i < bit1; ++i) {
		if(i < clear_most_significant_bits)
			EXPECT_TRUE(has_bit(input, i));
		else
			EXPECT_FALSE(has_bit(input, i));
	}
}