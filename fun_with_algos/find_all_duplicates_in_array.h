//
// Created by andreas on 25.03.24.
//

#ifndef FIND_ALL_DUPLICATES_IN_ARRAY_H
#define FIND_ALL_DUPLICATES_IN_ARRAY_H
// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and
// each integer appears once or twice, return an array of all the integers that appears twice.
// You must write an algorithm that runs in O(n) time and uses only constant extra space.
#include <vector>

std::vector<int> find_all_duplicates_in_array(std::vector<int>& nums) {
	std::vector<int> result;
	for(int i{}; i < nums.size(); ++i)
	{
		int index = std::abs(nums[i])-1;
		if(nums[index] < 0)
			result.push_back(std::abs(nums[i]));
		nums[index] = -nums[index];
	}
	return result;
}

#endif //FIND_ALL_DUPLICATES_IN_ARRAY_H
