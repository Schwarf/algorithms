//
// Created by andreas on 05.06.23.
//

#ifndef REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#include <vector>
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each
// unique element appears only once. The relative order of the elements should be kept the same.
// Then return the number of unique elements in nums.
// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
// - Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// - Return k.


template <typename T>
int remove_duplicates_from_sorted_array(std::vector<T> & elements)
{
	int index{1};
	for (int i{1}; i < elements.size(); ++i)
	{
		if(elements[i-1] != elements[i])
		{
			elements[index++] = elements[i];
		}
	}
	return index;
}

#endif //REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
