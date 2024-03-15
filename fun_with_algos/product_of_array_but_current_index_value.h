//
// Created by andreas on 15.03.24.
//

#ifndef PRODUCT_OF_ARRAY_BUT_CURRENT_INDEX_VALUE_H
#define PRODUCT_OF_ARRAY_BUT_CURRENT_INDEX_VALUE_H
//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//You must write an algorithm that runs in O(n) time and without using the division operation.
#include <vector>
template <typename T>
requires std::is_arithmetic_v<T>
std::vector<T> product_of_array_but_current_index_value(const std::vector<T> & input)
{
	int n = input.size();
	std::vector<T> products(n);

	T prefixProduct{1};
	for (int i{}; i < n; i++) {
		products[i] = prefixProduct;
		prefixProduct *= input[i];
	}
	int suffixProduct = 1;
	for (int i{n-1}; i > -1; i--) {
		products[i] *= suffixProduct;
		suffixProduct *= input[i];
	}
	return products;
}

#endif //PRODUCT_OF_ARRAY_BUT_CURRENT_INDEX_VALUE_H
