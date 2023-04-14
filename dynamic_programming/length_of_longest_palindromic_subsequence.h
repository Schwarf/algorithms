//
// Created by andreas on 14.04.23.
//

#ifndef LENGTH_OF_LONGEST_PALINDROMIC_SUBSEQUENCE_H
#define LENGTH_OF_LONGEST_PALINDROMIC_SUBSEQUENCE_H
#include <string>
#include <vector>
// Given a string input, find the longest palindromic subsequence's length in input.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no
// elements without changing the order of the remaining elements.

int longest_palindromic_subsequence(const std::string &input, int left, int right, std::vector<std::vector<int>> &memo)
{
	if (memo[left][right] != 0)
		return memo[left][right];
	if (left > right)
		return 0;
	if (left == right)
		return 1;
	if (input[left] == input[right])
		memo[left][right] = 2 + longest_palindromic_subsequence(input, left + 1, right - 1, memo);
	else
		memo[left][right] = std::max(longest_palindromic_subsequence(input, left + 1, right, memo),
									 longest_palindromic_subsequence(input, left, right - 1, memo));
	return memo[left][right];
}

// Classic dynamic programming with recursive top-down approach using memoization.
int length_of_longest_palindromic_subsequence(const std::string &input)
{
	int size = input.size();
	std::vector<std::vector<int>> memo(size, std::vector<int>(size));
	return longest_palindromic_subsequence(input, 0, size - 1, memo);
}


#endif //LENGTH_OF_LONGEST_PALINDROMIC_SUBSEQUENCE_H
