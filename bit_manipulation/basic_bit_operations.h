//
// Created by andreas on 04.04.23.
//

#ifndef BASIC_BIT_OPERATIONS_H
#define BASIC_BIT_OPERATIONS_H
#include <concepts>
#include <cstddef>
#include <bit>


template<typename T>
requires std::integral<T>
void is_valid_bit_position(const int bit_position)
{
	constexpr int maximum_bit_position{63};
	if (bit_position > maximum_bit_position || bit_position < 0)
		throw std::out_of_range(
			"Bit position must be greater than 0 and smaller than " + std::to_string(maximum_bit_position) + "!");
	uint64_t bit{1};
	bit <<= bit_position;
	if (bit >= static_cast<uint64_t>(std::numeric_limits<T>::max()))
		throw std::out_of_range(
			"Provided bit position " + std::to_string(bit_position) + " overflows in provided type !");
}

template<typename T>
requires std::integral<T>
bool has_bit(const T number, const int bit_position)
{
	is_valid_bit_position<T>(bit_position);
	return (number & (1 << bit_position)) != 0;
};

template<typename T>
requires std::integral<T>
void set_bit(T &number, const int bit_position)
{
	is_valid_bit_position<T>(bit_position);
	number |= (1 << bit_position);
};


template<typename T>
requires std::integral<T>
void clear_bit(T &number, const int bit_position)
{
	is_valid_bit_position<T>(bit_position);
	T mask = ~(1 << bit_position);
	number &= mask;
};

template<typename T>
requires std::integral<T>
void clear_most_significant_bits_until_position(T &number, const int bit_position)
{
	is_valid_bit_position<T>(bit_position);
	T mask = (1 << bit_position) - 1;
	number &= mask;
}

template<typename T>
requires std::integral<T>
void clear_bits_until_position(T &number, const int bit_position)
{
	is_valid_bit_position<T>(bit_position);
	T mask = (-1 << (bit_position + 1));
	number &= mask;
}


#endif //BASIC_BIT_OPERATIONS_H
