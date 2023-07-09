//
// Created by andreas on 09.07.23.
//

#ifndef LONGEST_PALINDROMIC_SUBSTRING_H
#define LONGEST_PALINDROMIC_SUBSTRING_H
#include <string>
#include <vector>
#include <functional>
std::string longest_palindromic_substring_with_memoization(const std::string &input_string)
{
	int n = input_string.length();
	std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));
	int max_length{};
	int start{};
	std::function<int(int, int)> find_longest_palindrome = [&](int left, int right) -> int
	{
		if (left > right)
			return 0;
		if (left == right)
			return 1;
		if (memo[left][right] != -1)
			return memo[left][right];
		if (input_string[left] == input_string[right])
			memo[left][right] = 2 + find_longest_palindrome(left + 1, right - 1);
		else
			memo[left][right] =
				std::max(find_longest_palindrome(left + 1, right), find_longest_palindrome(left, right - 1));
		return memo[left][right];
	};
	for (int i{}; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int length = find_longest_palindrome(i, j);
			if (length > max_length) {
				max_length = length;
				start = i;
			}
		}
	}
	return input_string.substr(start, max_length);

}


#endif //LONGEST_PALINDROMIC_SUBSTRING_H
