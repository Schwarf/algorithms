//
// Created by andreas on 06.10.23.
//

#ifndef MAXIMIZE_PRODUCT_FROM_GIVEN_TARGET_H
#define MAXIMIZE_PRODUCT_FROM_GIVEN_TARGET_H
#include <concepts>
#include <vector>
// Given an integer n, break it into the sum of k positive integers, where k >= 2,
// and maximize the product of those integers.
// Return the maximum product you can get.

template<typename T>
requires std::is_unsigned_v<T>
T maximize(T target, std::vector<T> &memo)
{
	if (target < 4)
		return target;
	if (memo[target] != 0)
		return memo[target];
	T result = target;
	for (T i{2}; i <= target; ++i) {
		result = std::max(result, i * maximize(target - i, memo));
	}
	memo[target] = result;
	return result;
}

template<typename T>
requires std::is_unsigned_v<T>
T maximize_product_top_down(T target)
{
	if (target < 4)
		return target - 1;
	auto memo = std::vector<T>(target + 1, 0);
	return maximize(target, memo);
}


#endif //MAXIMIZE_PRODUCT_FROM_GIVEN_TARGET_H
