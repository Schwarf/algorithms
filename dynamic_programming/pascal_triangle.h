//
// Created by andreas on 08.07.23.
//

#ifndef PASCAL_TRIANGLE_H
#define PASCAL_TRIANGLE_H
// Binomial coefficient is given as: (n k) = (n-1 k-1) + (n-1 k)
// Compute the binomial coefficient for n up to 50
// (n n) = 1 and (n 0) = 1

#include <array>
#include <stdexcept>

long long compute_binomial_coefficient(int n, int k)
{
	constexpr int max{51};
	if (n + 1 > max)
		throw std::out_of_range("Binomial coefficients are only computed up to 50!");
	std::array<std::array<long long, max>, max> dp{};
	for (int row{}; row <= n; ++row) {
		dp[row][row] = 1;
		dp[row][0] = 1;
	}
	for (int row{1}; row <= n; ++row) {
		for (int col{1}; col <= row; ++col) {
			dp[row][col] = dp[row - 1][col] + dp[row - 1][col - 1];
		}
	}
	return dp[n][k];
}

#include <array>
#include <stdexcept>

// Compute Pascal triangle at compile time
constexpr std::array<std::array<long long, 51>, 51> binomial_coefficients()
{
	std::array<std::array<long long, 51>, 51> coefficients{};
	for (int row{}; row <= 50; ++row) {
		coefficients[row][row] = 1;
		coefficients[row][0] = 1;
	}
	for (int row{1}; row <= 50; ++row) {
		for (int col{1}; col <= row; ++col) {
			coefficients[row][col] = coefficients[row - 1][col] + coefficients[row - 1][col - 1];
		}
	}
	return coefficients;
}


#endif //PASCAL_TRIANGLE_H
