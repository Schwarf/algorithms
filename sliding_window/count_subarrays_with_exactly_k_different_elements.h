//
// Created by andreas on 30.03.24.
//

#ifndef COUNT_SUBARRAYS_WITH_EXACTLY_K_DIFFERENT_ELEMENTS_H
#define COUNT_SUBARRAYS_WITH_EXACTLY_K_DIFFERENT_ELEMENTS_H

// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good array is an array where the number of different integers in that array is exactly k.
// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.
#include <vector>
#include <unordered_map>

template <typename T>
int count_subarrays_with_at_most_k_different_values(const std::vector<T> &input, int k)
{
	std::unordered_map<int, int> frequency_map;
	int left{};
	int count{};
	for(int right{}; right < input.size(); ++right)
	{
		frequency_map[input[right]]++;
		while(frequency_map.size() > k)
		{
			frequency_map[input[left]]--;
			if(frequency_map[input[left]] == 0)
				frequency_map.erase(input[left]);
			left++;
		}
		count += (right-left+1);
	}
	return count;
}

template <typename T>
int count_subarrays_with_exactly_k_different_elements(const std::vector<T> &input, int k)
{
	return count_subarrays_with_at_most_k_different_values(input, k) - count_subarrays_with_at_most_k_different_values(input, k-1);
}
#endif //COUNT_SUBARRAYS_WITH_EXACTLY_K_DIFFERENT_ELEMENTS_H
