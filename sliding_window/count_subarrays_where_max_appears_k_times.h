//
// Created by andreas on 29.03.24.
//

#ifndef COUNT_SUBARRAYS_WHERE_MAX_APPEARS_K_TIMES_H
#define COUNT_SUBARRAYS_WHERE_MAX_APPEARS_K_TIMES_H
// You are given an integer array nums and a positive integer k.
// Return the number of subarrays where the maximum element of nums appears
// at least k (required_frequency) times in that subarray.
// A subarray is a contiguous sequence of elements within an array.
#include <vector>
template <typename T>
long long count_subarrays_where_max_appears_k_times(const std::vector<T> & input, int required_frequency)
{
	auto max = *std::max_element(input.begin(), input.end());
	long long result{};
	int left{};
	for(int right{}; right < input.size(); ++right)
	{
		// we lower required_frequency to track how many max element we have passed already
		if(input[right] == max)
			required_frequency--;

		while(required_frequency==0)
		{
			// If we encounter max at left we increase required_frequency and leave the while loop
			if(input[left] == max)
				required_frequency++;
			left++;
		}
		// Here comes the trick. We add the value of left(-index) to the result since all former sub arrays
		// starting from [[0, left-1], right] have enough max elements.
		
		result += left;
	}
	return result;
}
#endif //COUNT_SUBARRAYS_WHERE_MAX_APPEARS_K_TIMES_H
