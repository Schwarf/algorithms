//
// Created by andreas on 09.07.23.
//

#ifndef LONGEST_PALINDROMIC_SUBSTRING_H
#define LONGEST_PALINDROMIC_SUBSTRING_H
#include <string>
#include <vector>
#include <functional>

std::string longest_palindromic_substring_with_tabulation(const std::string &input_string)
{
	int n = input_string.length();
	std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
	int max_length{1};
	int start{};
	// All substrings of length 1 are palindromic
	for (int i{}; i < n; ++i)
		dp[i][i] = true;

	// All substrings of length 2 are discovered
	for (int i{}; i < n - 1; ++i) {
		if (input_string[i] == input_string[i + 1]) {
			dp[i][i + 1] = true;
			max_length = 2;
			start = i;
		}
	}
	// All substrings of length greater than 2 are discovered
	// We check all substrings of length = 3..n
	for (int length{3}; length <= n; ++length) {
		// Since we determined the length, so the start of the substring must be smaller than n-length+1 to fit
		for (int i{}; i < n - length + 1; ++i) {
			// the index j of the current substring is given here
			int j = i + length - 1;
			// we check that the characters are th same at (i, j) and must make sure that the smaller
			// substring is also palindromic
			if (input_string[i] == input_string[j] && dp[i + 1][j - 1]) {
				dp[i][j] = true;
				max_length = length;
				start = i;
			}
		}

	}
	return input_string.substr(start, max_length);
}


#endif //LONGEST_PALINDROMIC_SUBSTRING_H
