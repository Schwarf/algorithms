//
// Created by andreas on 12.06.22.
//

#ifndef LONGEST_SUBARRAY_WITH_UNIQUE_ELEMENTS_H
#define LONGEST_SUBARRAY_WITH_UNIQUE_ELEMENTS_H
#include <unordered_map>
#include <vector>

// You are given an array of positive integers nums and want to erase a subarray containing unique elements.
// The score you get by erasing the subarray is equal to the sum of its elements.
// Return the maximum score you can get by erasing exactly one subarray.
// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is,
// if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

// Constraints:

// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4

template <typename T>
int sum_longest_subarray_with_unique_elements(std::vector<T> & input)
{
	if(input.empty())
		return 0;
	std::unordered_map<int, bool> help;
	int left{};
	int right{};
	T sum{};
	T max_sum{};
	while(right < input.size())
	{
		// If the element has been seen already, we increase left and subtract the element form the sum
		// e.g. 1(left),2,3,1(right)  the first one is removed and left advanced
		while(help[input[right]])
		{
			help[input[left]] = false;
			sum -= input[left];
			left++;
		}
		// Each element is added and tracked.
		sum += input[right];
		help[input[right]] = true;
		right++;
		max_sum = std::max(max_sum, sum);
	}

	return max_sum;
}

#endif //LONGEST_SUBARRAY_WITH_UNIQUE_ELEMENTS_H
