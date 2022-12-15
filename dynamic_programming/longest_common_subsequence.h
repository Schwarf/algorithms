//
// Created by andreas on 15.12.22.
//

#ifndef LONGEST_COMMON_SUBSEQUENCE_H
#define LONGEST_COMMON_SUBSEQUENCE_H
#include <string>
#include <vector>
#include <algorithm>
// Given two strings input1 and input2, return the length of their longest common subsequence.
// If there is no common subsequence, return 0.
int longest_common_sub_sequence(const std::string &input1, const std::string &input2)
{
	int s1 = input1.size();
	int s2 = input2.size();
	std::vector<std::vector<int>> dp(s1 + 1, std::vector<int>(s2 + 1));
	for (int i{}; i < s1; ++i) {
		for (int j{}; j < s2; ++j) {
			dp[i + 1][j + 1] = input1[i] == input2[j] ? dp[i][j] + 1 : std::max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	return dp[s1][s2];
}


#endif //LONGEST_COMMON_SUBSEQUENCE_H
