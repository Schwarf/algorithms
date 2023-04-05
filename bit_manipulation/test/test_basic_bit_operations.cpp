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

TEST(has_bit, returns_true)
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