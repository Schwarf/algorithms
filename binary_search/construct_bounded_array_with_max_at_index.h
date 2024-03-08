//
// Created by andreas on 10.06.23.
//

#ifndef CONSTRUCT_BOUNDED_ARRAY_WITH_MAX_AT_INDEX_H
#define CONSTRUCT_BOUNDED_ARRAY_WITH_MAX_AT_INDEX_H
// You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:
// - nums.length == n
// - nums[i] is a positive integer where 0 <= i < n.
// - abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
// - The sum of all the elements of nums does not exceed maxSum.
// - nums[index] is maximized.
// Return nums[index] of the constructed array.

#include <type_traits>
template<typename T>
T compute_sum(int index, T value, int n)
{
	T count{};
	if (value > index)
		// arithmetic sum = n*(a_1 + a_n)/2 with n = index+1, a_1 = value-index, a_n = value
		count += (value + value - index) * (index + 1) / 2;
	else
		// index greater equal value. That means we can fill the first value indices with 1..value but then we fill with 1.
		count += (value + 1) * value / 2 + (index - value + 1);
	// right side of index
	if (value >= n - index)
		// arithmetic sum = n*(a_1 + a_n)/2 with n = n-index, a_1 = value-n+1+index, a_n = value
		count += (value + value - n + 1 + index) * (n - index) / 2;
	else
		count += (value + 1) * value / 2 + (n - index - value);

	return count - value;
}
template<typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
T max_value_from_constructed_array(int n, int index, T max_sum)
{
	T left{1};
	T right{max_sum};
	while (left < right) {
		T mid = (left + right + 1) / 2;
		if (compute_sum(index, mid, n) <= max_sum)
			left = mid;
		else
			right = mid - 1;
	}
	return left;

}

#endif //CONSTRUCT_BOUNDED_ARRAY_WITH_MAX_AT_INDEX_H
