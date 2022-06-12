//
// Created by andreas on 12.06.22.
//

#ifndef LONGEST_SUBARRAY_WITH_UNIQUE_ELEMENTS_H
#define LONGEST_SUBARRAY_WITH_UNIQUE_ELEMENTS_H
#include <unordered_map>
#include <vector>

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
		while(help[input[right]])
		{
			help[input[left]] = false;
			sum -= input[left];
			left++;
		}

		sum += input[right];
		help[input[right]] = true;
		right++;
		max_sum = std::max(max_sum, sum);
	}

	return max_sum;
}

#endif //LONGEST_SUBARRAY_WITH_UNIQUE_ELEMENTS_H
