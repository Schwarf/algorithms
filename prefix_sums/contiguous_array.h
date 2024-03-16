//
// Created by andreas on 16.03.24.
//

#ifndef CONTIGUOUS_ARRAY_H
#define CONTIGUOUS_ARRAY_H
// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
#include <vector>
#include <unordered_map>
int find_max_contiguous_array(const std::vector<int> & input)
{
	std::unordered_map<int, int> help;
	help[0] = -1;
	int max_length{};
	int counter{};
	for(int i{}; i < input.size(); ++i)
	{
		counter += input[i] ? 1 : -1;
		// The algorithm is base on the idea that between equal prefix sums the number of 0s and 1s is equal.
		// So whenever we encounter a prefix-sum a second time we look up the index when it appeared first.
		// The appearance of a prefix sum is never updated (only for the first time see 'else'-branch).
		if(help.find(counter) != help.end())
			max_length = std::max(max_length, i - help[counter]);
		else
			help[counter] = i;
	}
	return max_length;

}
#endif //CONTIGUOUS_ARRAY_H
