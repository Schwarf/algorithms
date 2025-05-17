//
// Created by andreas on 09.10.22.
//

#ifndef THREE_SUM_CLOSEST_H
#define THREE_SUM_CLOSEST_H
#include <vector>
#include <algorithm>

// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is
// closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
// 3 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// -10^4 <= target <= 10^4


template<typename T>
int three_sum_closest(std::vector<T> &input, int target_value)
{
	std::sort(input.begin(), input.end());
	auto n = input.size();
	auto sum = input[0] + input[1] + input[n - 1];
	int new_sum{-100000};
	for (size_t index{}; index < n; ++index) {
		size_t left = index + 1;
		size_t right = n - 1;
		while (left < right) {
			new_sum = input[index] + input[left] + input[right];
			if (new_sum == target_value)
				return new_sum;
			if (new_sum < target_value)
				++left;
			else
				--right;
			if (std::abs(new_sum - target_value) < std::abs(sum - target_value))
				sum = new_sum;
		}

	}
	return sum;
}
#endif //THREE_SUM_CLOSEST_H
