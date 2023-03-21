//
// Created by andreas on 21.03.23.
//

#ifndef SUBARRAY_PRODUCT_LESS_THAN_H
#define SUBARRAY_PRODUCT_LESS_THAN_H
// Given an array 'input' and a value 'max',
// return the number of contiguous subarrays where the product of all the elements in the subarray is
// strictly less than 'max'.
#include <vector>
#include <concepts>
template<typename T, typename std::is_arithmetic<T>>
int number_of_subarrays_less_than(const std::vector<T> &input, T max_value)
{
	int left{};
	T product{};
	int result{};
	for (int right{}; right < input.size(); ++right) {
		product *= input[right];
		while (product >= max_value)
			product /= input[left++];
		result += right - left + 1;
	}
	return result;

}

#endif //SUBARRAY_PRODUCT_LESS_THAN_H
