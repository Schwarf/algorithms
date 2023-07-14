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
// O (N^2)
template<typename T>
requires std::is_arithmetic_v<T>
int size_of_longest_increasing_subsequence_bottom_up(const std::vector<T> &sequence)
{
	int n = sequence.size();
	std::vector<int> dp(n, 1);
	for (int i{1}; i < n; ++i) {
		for (int j{}; j < i; ++j) {
			if (sequence[i] > sequence[j])
				dp[i] = std::max(dp[i], dp[j] + 1);
		}
	}
	return *std::max_element(dp.begin(), dp.end());
}

// Optimized version of dynamic programming approach working in O(N*logN)
// Start iterating from the left.
// For each element in the sequence, find the first element in the tail_array that is greater than or equal to it
// using binary search. Replace that element with the current one.
// This replacement doesn't change the length of the longest increasing subsequence but ensures the potential
// for future elements to extend the subsequence. If no such element exists, then the current element can
// extend the existing longest increasing subsequence, so append it to the tail_array.
int size_of_longest_increasing_subsequence_tail_list(const std::vector<int> &sequence)
{
	std::vector<int> tail_array;
	const int n = sequence.size();
	for (int i = 0; i < n; i++) {
		// We search for the FIRST element in the sorted tail_array that is greater equal the element sequence[i]
		// If we find one (the FIRST one) that is greater we replace it with the current sequence element sequence[i].
		// If not we append the sequence[i] element to the array. In that way the 'last' element of tail array
		// is always the smallest possible optimizing for length.
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
