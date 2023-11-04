//
// Created by andreas on 30.10.23.
//

#ifndef SORT_ACCORDING_TO_HAMMING_WEIGHT_H
#define SORT_ACCORDING_TO_HAMMING_WEIGHT_H
#include <concepts>
#include <vector>
#include <algorithm>

#include "basic_bit_operations.h"

template <typename Function, typename Argument>
concept CallableWithSingleIntegralArgument = requires(Function function, Argument &&argument)
{
	{function(argument) }-> std::convertible_to<size_t>;
} && std::is_integral_v<std::remove_reference_t< Argument>>;

template<typename T, typename HammingWeightFunction>
requires CallableWithSingleIntegralArgument<HammingWeightFunction, T&>
void sort_according_to_hamming_weight(std::vector<T> & input, HammingWeightFunction hamming_func)
{
	auto compare = [&](T i1, T i2)
	{
		if(hamming_func(i1) != hamming_func(i2))
			return hamming_func(i1) < hamming_func(i2);
		return i1 < i2;
	};
	std::sort(input.begin(), input.end(), compare);
}



#endif //SORT_ACCORDING_TO_HAMMING_WEIGHT_H
