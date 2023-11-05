//
// Created by andreas on 21.03.23.
//

#ifndef SUBARRAY_PRODUCT_LESS_THAN_H
#define SUBARRAY_PRODUCT_LESS_THAN_H
// Given an array 'input' and a value 'max',
// return the number of contiguous sub-arrays where the product of all the elements in the subarray is
// strictly less than 'max'.
#include <vector>
#include <concepts>
template<typename T, typename = typename std::enable_if<std::is_integral_v<T>>>
T number_of_subarrays_less_than(const std::vector<T> &input, const T max_value)
{
	if(max_value < 2)
		return 0;
	T left{};
	T product{1};
	T result{};
	for (T right{}; right < input.size(); ++right) {
		product *= input[right];
		while (product >= max_value)
			product /= input[left++];
		result += right - left + 1;
	}
	return result;

}

#endif //SUBARRAY_PRODUCT_LESS_THAN_H
