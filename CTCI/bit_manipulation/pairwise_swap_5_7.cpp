//
// Created by andreas on 20.09.22.
//

#include <iostream>
#include <vector>

// we want to swap all even bits with all odd bits
// code below only works for 32bit integers, adapt bit-mask for 64 integers
// requires some testing
unsigned int pairwise_swap(unsigned int number)
{
	auto mask_for_odd_bits = 0xaaaaaaaa;
	auto mask_for_even_bits = 0x55555555;
	return (((number & mask_for_odd_bits)) >> 1 | ((number & mask_for_even_bits) << 1));
}

