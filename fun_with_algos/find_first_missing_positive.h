//
// Created by andreas on 26.03.24.
//

#ifndef FIND_FIRST_MISSING_POSITIVE_H
#define FIND_FIRST_MISSING_POSITIVE_H
// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
#include <vector>
// O(N) space using bool vector
int find_first_missing_positive(const std::vector<int>& nums) {
	std::vector<bool> missing(nums.size()+1, true);
	for(int i=0; i < nums.size(); ++i)
	{
		if(nums[i] > -1 && nums[i] <=nums.size())
			missing[nums[i]] = false;
	}
	for(int i{1}; i <= nums.size()+1; ++i)
	{
		if(missing[i])
			return i;
	}
	return nums.size();
}

int find_first_missing_positive_optimized(std::vector<int>& nums) {
	int n = nums.size();
	bool contains_value_1{};

	// Check if array conatin the value 1. Set all non-positive values to 1.
	for (int i {}; i < n; i++) {
		// Check whether 1 is in the original array
		if (nums[i] == 1) {
			contains_value_1 = true;
		}
		if (nums[i] <= 0 || nums[i] > n) {
			nums[i] = 1;
		}
	}
	// Does not contain, return 1 as first missing positive integer.
	if (!contains_value_1)
		return 1;

	// Mark whether integers 1 to n are in nums
	// Use index as a hash key and negative sign as a presence detector.
	for (int i{}; i < n; i++) {
		int index = abs(nums[i]);
		// since 0-index is not use, use it for index=n
		if (index == n) {
			nums[0] = - abs(nums[0]);
		} else {
			nums[index] = - abs(nums[index]);
		}
	}

	// We negated all values at the appearing indices in the array. The first value greater 0
	// has as index the first missing positive integer
	for (int i{1}; i < n; i++) {
		if (nums[i] > 0)
			return i;
	}

	// nums[0] stores whether n is in nums
	if (nums[0] > 0) {
		return n;
	}
	// If all former value were negative, we return n+1 as the first missing integer
	return n + 1;
}
#endif //FIND_FIRST_MISSING_POSITIVE_H
