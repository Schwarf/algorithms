//
// Created by andreas on 20.07.22.
//

#ifndef LONGEST_INCREASING_SUBSEQUENCE_H
#define LONGEST_INCREASING_SUBSEQUENCE_H
#include <vector>
#include <algorithm>
#include <concepts>


// Runtime complexity is 2^N because we branch into two recursive calls in each function call.
template<typename T>
requires std::is_arithmetic_v<T>
int size_of_longest_increasing_subsequence_recursive(const std::vector<T> &sequence,
													 int previous_element = std::numeric_limits<T>::min(),
													 int index = 0)
{
	if (index == sequence.size())
		return 0;
	int exclude_current_element =
		size_of_longest_increasing_subsequence_recursive(sequence, previous_element, index + 1);
	int include_current_element{};
	if (sequence[index] > previous_element)
		include_current_element =
			1 + size_of_longest_increasing_subsequence_recursive(sequence, sequence[index], index + 1);

	return std::max(exclude_current_element, include_current_element);
}
// Runtime complexity is N^2 because each cell in 2D-array memo is filled exactly once.
template<typename T>
requires std::is_arithmetic_v<T>
int memoization(const std::vector<T> &sequence,
				std::vector<std::vector<int>> &memo,
				int current_index,
				int previous_index)
{
	if (current_index == sequence.size())
		return 0;
	if (memo[previous_index + 1][current_index] != -1)
		return memo[previous_index + 1][current_index];

	int exclude_current_element = memoization(sequence, memo, current_index + 1, previous_index);
	int include_current_element{};
	if (previous_index == -1 || sequence[current_index] > sequence[previous_index])
		include_current_element =
			1 + memoization(sequence, memo, current_index + 1, current_index);

	memo[previous_index + 1][current_index] = std::max(exclude_current_element, include_current_element);
	return memo[previous_index + 1][current_index];
}

template<typename T>
requires std::is_arithmetic_v<T>
int size_of_longest_increasing_subsequence_top_down(const std::vector<T> &sequence)
{
	std::vector<std::vector<int>> memo(sequence.size(), std::vector<int>(sequence.size(), -1));
	return memoization(sequence, memo, 0, -1);
}

// O(N^2)
int size_of_longest_increasing_subsequence(const std::vector<int> &sequence)
{
	const int size = sequence.size();
	std::vector<int> help(size, 1);
	for (int i{1}; i < size; i++) {
		for (int j{0}; j < i; j++) {
			if (sequence[i] > sequence[j]) {
				help[i] = std::max(help[i], help[j] + 1);
			}
		}
	}
//	for(const auto & element : help)
//		std::cout << element << std::endl;
	return *std::max_element(help.begin(), help.end());
}

// O(N*logN) ???
int size_of_longest_increasing_subsequence2(const std::vector<int> &sequence)
{
	std::vector<int> tail_array;
	const int n = sequence.size();
	for (int i = 0; i < n; i++) {
		// We search for the FIRST element in the sorted tail_array that is greater equal the element sequence[i]
		// If we find one (the FIRST one) that is greater we replace it with the current sequence element sequence[i].
		// If not we append the sequence[i] element to the array.
		auto it = lower_bound(tail_array.begin(), tail_array.end(), sequence[i]);
		if (it != tail_array.end()) {
			*it = sequence[i];
		}
		else {
			tail_array.push_back(sequence[i]);
		}

	}
	return tail_array.size();
}


#endif //LONGEST_INCREASING_SUBSEQUENCE_H
