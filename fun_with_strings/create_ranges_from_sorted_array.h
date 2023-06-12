//
// Created by andreas on 12.06.23.
//

#ifndef CREATE_RANGES_FROM_SORTED_ARRAY_H
#define CREATE_RANGES_FROM_SORTED_ARRAY_H
// You are given a sorted unique integer array nums.
// A range [a,b] is the set of all integers from a to b (inclusive).
// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
// Each range [a,b] in the list should be output as:
// "a->b" if a != b
// "a" if a == b
#include <vector>
#include <string>
std::vector<std::string> create_ranges_from_sorted_array(const std::vector<int>& input) {
	std::vector<std::string> result;
	for(int i{}; i < input.size(); ++i)
	{
		int current = input[i];
		while(i+1 < input.size() && input[i]+1 == input[i+1])
			i++;
		if(input[i] == current )
			result.push_back(std::to_string(current));
		else
			result.push_back(std::to_string(current)+"->"+std::to_string(input[i]));
	}
	return result;
}



#endif //CREATE_RANGES_FROM_SORTED_ARRAY_H
