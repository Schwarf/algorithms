//
// Created by andreas on 04.07.23.
//

#ifndef FIND_UNIQUE_NUMBER_IN_ARRAYS_H
#define FIND_UNIQUE_NUMBER_IN_ARRAYS_H
#include <vector>
#include <concepts>
//Given an integer array nums where every element appears two times except for one, which appears exactly once.
// Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.

template<typename T>
requires std::is_integral_v<T>
T find_unique_number_in_array_with_pairs(const std::vector<T> & input)
{
	T x{};
	for(const auto & element: input)
		x ^= element;
	return x;
}


#endif //FIND_UNIQUE_NUMBER_IN_ARRAYS_H
