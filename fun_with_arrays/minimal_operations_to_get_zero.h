//
// Created by andreas on 12.06.22.
//

#ifndef MINIMAL_OPERATIONS_ARRAY_ELEMENTS_TO_GET_ZERO_TARGET_H
#define MINIMAL_OPERATIONS_ARRAY_ELEMENTS_TO_GET_ZERO_TARGET_H
#include <vector>

// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the
// rightmost element from the array nums and subtract its value from x. Note that
// this modifies the array for future operations.
// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

// Constraints:
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4
// 1 <= x <= 10^9

template<typename T>
int minimal_operations_to_get_zero(std::vector<T> &input, T target)
{
	T sum{};
	for (const auto &element: input)
		sum += element;
	if (sum == target)
		return input.size();
	if (sum < target)
		return -1;

	target = sum - target;
	T current_sum{};
	int start_index{};
	int count_operations{};
	for (int i = 0; i < input.size(); ++i) {
		current_sum += input[i];
		while (current_sum > target)
			current_sum -= input[start_index++];
		if (current_sum == target)
			count_operations = std::max(count_operations, i - start_index + 1);
	}
	return count_operations == 0 ? -1 : input.size() - count_operations;
}


#endif //MINIMAL_OPERATIONS_ARRAY_ELEMENTS_TO_GET_ZERO_TARGET_H
