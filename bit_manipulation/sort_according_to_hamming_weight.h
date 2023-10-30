//
// Created by andreas on 30.10.23.
//

#ifndef SORT_ACCORDING_TO_HAMMING_WEIGHT_H
#define SORT_ACCORDING_TO_HAMMING_WEIGHT_H
#include <concepts>
#include <vector>
#include <algorithm>

#include "basic_bit_operations.h"

template<typename T>
requires std::is_integral_v<T>
void sort_according_to_hamming_weight(std::vector<T> & input)
{
	auto compare = [&](const T i1, const T i2)
	{
		if(get_hamming_weight_inefficient(i1) != get_hamming_weight_inefficient(i2))
			return get_hamming_weight_inefficient(i1) < get_hamming_weight_inefficient(i2);
		return i1 < i2;
	};
	std::sort(input.begin(), input.end(), compare);
}



#endif //SORT_ACCORDING_TO_HAMMING_WEIGHT_H
