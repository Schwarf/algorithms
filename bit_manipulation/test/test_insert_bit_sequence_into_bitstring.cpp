//
// Created by andreas on 10.04.23.
//
#include "gtest/gtest.h"
#include "insert_bit_sequence_into_bitstring.h"
#include "basic_bit_operations.h"

TEST(TestInsertBitSequenceIntoBitString, simple)
{
	int bitstring = 1 << 11;
	int bit_sequence = (1 << 4) + (1 << 1) + (1 << 0);
	int left_start = 6;
	int right_end = 2;
	std::vector<bool> expected_bits(32);
	expected_bits[11] = true;
	expected_bits[2] = true;
	expected_bits[3] = true;
	expected_bits[6] = true;
	insert_bit_sequence_into_bitstring(bitstring, bit_sequence, left_start, right_end);
	for (int i{}; i < 31; ++i)
	{
		if(expected_bits[i])
			EXPECT_TRUE(has_bit(bitstring, i));
	}
}

TEST(TestInsertBitSequenceIntoBitString, simple2)
{
	int bitstring = 1 << 30;
	int bit_sequence = (1 << 8) -1;
	int left_start = 22;
	int right_end = 15;
	std::vector<bool> expected_bits(32);
	expected_bits[30] = true;
	expected_bits[15] = true;
	expected_bits[16] = true;
	expected_bits[17] = true;
	expected_bits[18] = true;
	expected_bits[19] = true;
	expected_bits[20] = true;
	expected_bits[21] = true;
	expected_bits[22] = true;
	insert_bit_sequence_into_bitstring(bitstring, bit_sequence, left_start, right_end);
	for (int i{}; i < 31; ++i)
	{
		std::cout << has_bit(bitstring, i) << ", ";
		if(expected_bits[i])
			EXPECT_TRUE(has_bit(bitstring, i));
	}
}