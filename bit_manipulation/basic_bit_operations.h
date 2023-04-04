//
// Created by andreas on 04.04.23.
//

#ifndef BASIC_BIT_OPERATIONS_H
#define BASIC_BIT_OPERATIONS_H
#include <concepts>
#include <cstddef>
#include <bit>


template <typename T, int maximum_bit_position>
requires std::integral<T>
bool has_bit(T number, int bit_position)
{
	if (bit_position > maximum_bit_position)
		throw std::out_of_range("Bit position must be smaller than " + std::to_string(maximum_bit_position)+"!");
	uint64_t bit = (1<<bit_position);
	if(bit > static_cast<uint64_t>(std::numeric_limits<T>::max()))
		throw std::out_of_range("Bit position overflows in provided type !");
	return (number & 1 << bit_position) != 0;


};

#endif //BASIC_BIT_OPERATIONS_H
