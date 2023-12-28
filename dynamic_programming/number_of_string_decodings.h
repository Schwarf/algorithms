//
// Created by andreas on 28.12.23.
//

#ifndef NUMBER_OF_STRING_DECODINGS_H
#define NUMBER_OF_STRING_DECODINGS_H
#include <string>
#include <vector>
// A message containing letters from A-Z can be encoded into numbers using the following mapping:
// 'A' -> "1", 'B' -> "2", ..., 'Z' -> "26"
// To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
// Given a string s containing only digits, return the number of ways to decode it.
// The test cases are generated so that the answer fits in a 32-bit integer.

int number_of_decodings_bottom_up(const std::string &s)
{
	if (s.empty() || s[0] == '0')
		return 0;
	int n = s.size();
	std::vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i{2}; i <= n; ++i) {
		int oneDigit = stoi(s.substr(i - 1, 1));
		int twoDigits = stoi(s.substr(i - 2, 2));

		if (oneDigit >= 1) {
			dp[i] += dp[i - 1];
		}
		if (twoDigits >= 10 && twoDigits <= 26) {
			dp[i] += dp[i - 2];
		}
	}
	return dp[n];
}

#endif //NUMBER_OF_STRING_DECODINGS_H

