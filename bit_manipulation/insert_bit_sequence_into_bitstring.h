//
// Created by andreas on 10.04.23.
//

#ifndef INSERT_BIT_SEQUENCE_INTO_BITSTRING_H
#define INSERT_BIT_SEQUENCE_INTO_BITSTRING_H
void insert_bit_sequence_into_bitstring(int &bitstring,
										int bit_sequence,
										int left_start_position,
										int right_end_position)
{
	if (right_end_position > left_start_position || left_start_position >= 32 || right_end_position < 0)
		return ;
	int all_bits_set = ~0;
	int left = left_start_position < 31 ? (all_bits_set << (left_start_position + 1)) : 0;
	int right = (1 << right_end_position) - 1;
	int mask = left + right;
	int clear_bitstring_between_left_and_right = bitstring & mask;
	int shift_bit_sequence_in_position = bit_sequence << right_end_position;
	bitstring = clear_bitstring_between_left_and_right | shift_bit_sequence_in_position;
}

#endif //INSERT_BIT_SEQUENCE_INTO_BITSTRING_H
