//
// Created by andreas on 04.12.22.
//

#include <unordered_map>
#include <vector>

#ifndef GET_MAJORITY_ELEMENT_H
#define GET_MAJORITY_ELEMENT_H
// The majority element in an array of length n appears at least n/2 times in the array. Find it. input-element between
// +/- 10^9
int get_majority_element_hashmap(const std::vector<int>& input)
{
	std::unordered_map<int, int> counter;
	for(const auto & element: input)
	{
		if(++counter[element] > input.size()/2)
			return element;
	}
	return {};
}

int get_majority_element_bit_manipulation(const std::vector<int>& input)
{
	int majority_element{};
	// Works because we are between +/-10**9
	for(int i{}; i < 32; ++i)
	{
		int current_bit = 1 << i;
		int current_bit_count{};
		for(const auto & element : input)
			current_bit_count += (element & current_bit) ? 1: 0;
		// Set bit in majority_element
		if(current_bit_count > input.size()/2)
			majority_element |= current_bit;
	}
	return majority_element;
}


#endif //GET_MAJORITY_ELEMENT_H
