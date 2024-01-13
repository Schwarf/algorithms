//
// Created by andreas on 12.06.23.
//

#ifndef LEVENSHTEIN_DISTANCE_H
#define LEVENSHTEIN_DISTANCE_H
#include <string>
#include <vector>
#include <algorithm>

int levenshtein_distance(const std::string &word1, const std::string &word2)
{
	int n1 = word1.length();
	int n2 = word2.length();
	if(n1 == 0 && n2 == 0)
		return 0;
	if(n1 == 0)
		return n2;
	if(n2 == 0)
		return n1;

	std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
	for (int i{}; i < n1; ++i)
		dp[i][0] = i;
	for (int i{}; i < n2; ++i)
		dp[0][i] = i;

	for (int i{1}; i <= n1; ++i) {
		for (int j{1}; j <= n2; ++j) {
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
			}
		}
	}
	return dp[n1][n2];
}
#endif //LEVENSHTEIN_DISTANCE_H
