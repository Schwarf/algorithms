//
// Created by andreas on 10.02.24.
//

#ifndef COUNT_PALINDROMIC_SUBSTRINGS_H
#define COUNT_PALINDROMIC_SUBSTRINGS_H
#include <string>
bool is_palindrome(const std::string &s)
{
	int left{};
	int right = s.size() - 1;
	while (left < right && s[left] == s[right]) {
		left++;
		right--;
	}
	return left >= right;
}

int count_palindromic_substrings_no_dynamic_programming(const std::string &s)
{
	int n = s.size();
	int count{};
	for (int i{}; i < n; ++i) {
		for (int j{i}; j < n; ++j) {
			if (is_palindrome(s.substr(i, j - i + 1))) {
				count++;
			}
		}
	}
	return count;
}

int count_palindromes_around_center(const std::string &s, int left, int right)
{
	int count = 0;
	while (left >= 0 && right < s.length() && s[left] == s[right]) {
		// Found a palindrome, increment count and expand around center
		count++;
		left--;
		right++;
	}
	return count;
}

int count_palindromic_substrings_with_dp(const std::string &s)
{
	int count{};
	for (int i{}; i < s.length(); ++i) {
		// Count odd-length palindromes with center at i
		count += count_palindromes_around_center(s, i, i);
		// Count even-length palindromes with center at i and i+1
		count += count_palindromes_around_center(s, i, i + 1);
	}
	return count;
}


#endif //COUNT_PALINDROMIC_SUBSTRINGS_H
