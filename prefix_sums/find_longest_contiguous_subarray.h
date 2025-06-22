//
// Created by andreas on 13.04.23.
//

#ifndef CONTIGEOUS_ARRAY_H
#define CONTIGEOUS_ARRAY_H
#include <unordered_map>
#include <vector>

// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1
// aka 'true' and 'false'.
int find_longest_contiguous_subarray(std::vector<int>& nums) {
	// This hashmap is used to store the count (of 0 and 1) and the index. 0 is counted as -1 and 1 as 1. Whenever
	// we encounter the same count 'c' again we have equal number of 0's and 1's in the array.
	// Then we compute the distance to the former index where count was 'c'.
	std::unordered_map<int, int> help;
	help[0] = -1;
	int max{};
	int count{};

	for(int i{}; i < nums.size(); ++i)
	{
		// Update count
		count += nums[i] ? 1: -1;
		// Have we found this count before than find distance to it. And update max accordingly.
		if(help.find(count) != help.end())
			max = std::max(max, i - help[count]);
		else
			help[count] = i;
	}
	return max;
}


#endif //CONTIGEOUS_ARRAY_H
