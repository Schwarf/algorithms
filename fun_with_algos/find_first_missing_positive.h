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

#endif //FIND_FIRST_MISSING_POSITIVE_H
