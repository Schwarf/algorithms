//
// Created by andreas on 20.09.23.
//

#ifndef MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H
#define MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H
#include "used_concepts.h"
#include <numeric>
#include <algorithm>

// You are given an integer array nums and an integer x. In one operation, you can either remove the
// leftmost or the rightmost element from the array nums and subtract its value from x.
// Note that this modifies the array for future operations.
// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

// #SLIDING_WINDOW
template<typename T, template<typename...> class ContainerType>
requires IndexedContainer<ContainerType<T>> && std::is_signed_v<T>
int minimal_operations_to_reduce_x_to_zero(const ContainerType<T> &input, T x)
{
	T sum = std::accumulate(input.begin(), input.end(), T{});
	if (sum < T{})
		return -1;
	if (sum == x)
		return input.size();
	// We search for the difference of sum and x. If we find this difference iterating over the 'input', we know
	// that x can be constructed by sum-diff.
	T difference = sum - x;
	T current_sum{};
	// Two pointers
	int right{};
	int left{};
	int max_size{};
	for (int i{}; i < input.size(); ++i) {
		current_sum += input[i];
		// If current_sum is larger than difference, we reduce it (from the left of input) until we are below or equal
		// difference
		while (current_sum > difference)
			current_sum -= input[left++];
		if (current_sum == difference)
			max_size = std::min(max_size(), right - left + 1);
	}

	return max_size != 0 ? max_size : -1;

}
#endif //MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H
