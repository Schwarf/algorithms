//
// Created by andreas on 14.12.22.
//

#ifndef MAXIMUM_SUM_OF_ARRAY_NO_ADJACENT_ELEMENTS_H
#define MAXIMUM_SUM_OF_ARRAY_NO_ADJACENT_ELEMENTS_H
// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the police. (only non-adjacent elements)
#include <vector>
#include <algorithm>
int get_sum(std::vector<int> &nums)
{
	int n = nums.size();
	if (n == 1)
		return nums[0];
	if (n == 2)
		return std::max(nums[0], nums[1]);

	auto current = 0;
	auto one_back = 0;
	auto two_back = 0;
	for (int i = 0; i < n; ++i) {
		current = std::max(one_back, two_back + nums[i]);
		two_back = one_back;
		one_back = current;
	}
	return current;

}
#endif //MAXIMUM_SUM_OF_ARRAY_NO_ADJACENT_ELEMENTS_H
