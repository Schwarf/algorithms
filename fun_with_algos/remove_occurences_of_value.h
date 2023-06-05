//
// Created by andreas on 05.06.23.
//

#ifndef REMOVE_OCCURENCES_OF_VALUE_H
#define REMOVE_OCCURENCES_OF_VALUE_H
#include <vector>
// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
// The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do
// the following things:
// - Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
//   The remaining elements of nums are not important as well as the size of nums.
// - Return k.

template<typename T>
int remove_value(std::vector<int> & elements, T value_to_remove)
{
	int index{};
	for(const auto & element: elements)
	{
		if(element != value_to_remove)
			elements[index++] = element;
	}
	return index;
}

#endif //REMOVE_OCCURENCES_OF_VALUE_H
