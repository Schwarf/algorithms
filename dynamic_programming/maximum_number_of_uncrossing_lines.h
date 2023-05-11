//
// Created by andreas on 11.05.23.
//

#ifndef MAXIMUM_NUMBER_OF_UNCROSSING_LINES_H
#define MAXIMUM_NUMBER_OF_UNCROSSING_LINES_H
#include <concepts>
#include <vector>

// You are given two integer arrays nums1 and nums2. We write the integers of input1 and input2
// (in the order they are given) on two separate horizontal lines.
// We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
// input1[i] == input2[j], and
// the line we draw does not intersect any other connecting (non-horizontal) line.
// Note that a connecting line cannot intersect even at the endpoints (i.e., each number can
// only belong to one connecting line).
// Return the maximum number of connecting lines we can draw in this way.
template<typename T>
requires std::is_integral_v<T>
int maximum_number_of_uncrossing_lines(std::vector<T> &input1, std::vector<T> &input2)
{
	int n1 = input1.size();
	int n2 = input2.size();
	std::vector<std::vector<T>> dp(n1 + 1, std::vector<T>(n2 + 1, T{}));
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (input1[i - 1] == input2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	return dp[n1][n2];
}

#endif //MAXIMUM_NUMBER_OF_UNCROSSING_LINES_H
