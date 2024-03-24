//
// Created by andreas on 24.03.24.
//

#ifndef FIND_DUPLICATE_IN_ARRAY_H
#define FIND_DUPLICATE_IN_ARRAY_H

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.
#include <vector>
// Easy-peasy: Sort and find the duplicate. Here we concentrate on O(N) solutions.

int find_duplicate(std::vector<int>& input) {
	for(int i{}; i < input.size(); ++i)
	{
		// We compute the index and negate the value at the index.
		int index = std::abs(input[i]);
		// If the value at the index is already negative, we return the index because it has been visited once before/
		if(input[index] < 0)
			return index;
		// HERE we negate
		input[index] = -input[index];
	}
	return -1;
}


#endif //FIND_DUPLICATE_IN_ARRAY_H
