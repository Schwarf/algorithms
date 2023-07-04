//
// Created by andreas on 04.07.23.
//

#ifndef FIND_UNIQUE_NUMBER_IN_ARRAYS_H
#define FIND_UNIQUE_NUMBER_IN_ARRAYS_H
#include <vector>
#include <concepts>
#include <limits>
//Given an integer array nums where every element appears TWO times except for one, which appears exactly once.
// Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.

template<typename T>
requires std::is_integral_v<T>
T find_unique_number_in_array_with_pairs(const std::vector<T> & input)
{
	T result{};
	for(const auto & element: input)
		result ^= element;
	return result;
}


//Given an integer array nums where every element appears THREE times except for one, which appears exactly once.
// Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.

template<typename T>
requires std::is_integral_v<T>
T find_unique_number_in_array_with_triples(const std::vector<T> & input)
{
	T result{};
	constexpr int number_of_bits{std::numeric_limits<T>::digits};
	for(int i{}; i < number_of_bits; ++i)
	{
		T sum{};
		// We add the bits of al numbers in the input and divide the sum by three.
		// The modulo-rest shows if the bit is to set.
		for(const auto & element: input)
			sum += ((element>> i) & 1);
		sum %=3;
		result |= sum << i;
	}
	return result;
}

#endif //FIND_UNIQUE_NUMBER_IN_ARRAYS_H
