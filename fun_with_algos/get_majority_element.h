//
// Created by andreas on 04.12.22.
//

#include <unordered_map>
#include <vector>

#ifndef GET_MAJORITY_ELEMENT_H
#define GET_MAJORITY_ELEMENT_H
// The majority element in an array of length n appears at least n/2 times in the array. Find it
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


#endif //GET_MAJORITY_ELEMENT_H
