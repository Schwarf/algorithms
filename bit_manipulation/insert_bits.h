//
// Created by andreas on 14.06.25.
//

#ifndef INSERT_BITS_H
#define INSERT_BITS_H
// Insertion: You are given two 32-bit numbers, N and M, and two bit positions, i and
// j. Write a method to insert M into N such that M starts at bit j and ends at bit i. You
// can assume that the bits j through i have enough space to fit all of M. That is, if
// M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for
// example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.

// M = source
// N = target
// j = start
// i = end
int insert_bits(int target, int source,  int lower_bit, int higher_bit)
{
     int all_ones = ~0;
     int left = all_ones << (higher_bit + 1);
     int right = (1 << lower_bit) - 1;
     int mask_for_source_in_target = left | right;
     int clear_in_target = target & mask_for_source_in_target;
     int shifted_source  = source << lower_bit;
     return clear_in_target | shifted_source;
}

#endif //INSERT_BITS_H
