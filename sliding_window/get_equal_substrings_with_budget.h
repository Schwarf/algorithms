//
// Created by andreas on 17.01.24.
//

#ifndef GET_EQUAL_SUBSTRINGS_WITH_BUDGET_H
#define GET_EQUAL_SUBSTRINGS_WITH_BUDGET_H
// You are given two strings s and t of the same length and an integer maxCost.
// You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]|
// (i.e., the absolute difference between the ASCII values of the characters).
// Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t
// with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.
#include <string>
int get_equal_substring_with_budget(std::string s, std::string t, int budget) {
	int left{};
	for (int right{}; right < s.length(); ++right) {
		budget -= abs(s[right] - t[right]);
		if (budget < 0)
			budget += abs(s[left] - t[left++]);
	}

	return s.length() - left;
}

#endif //GET_EQUAL_SUBSTRINGS_WITH_BUDGET_H
