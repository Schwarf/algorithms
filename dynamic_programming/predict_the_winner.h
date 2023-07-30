//
// Created by andreas on 28.07.23.
//

#ifndef PREDICT_THE_WINNER_H
#define PREDICT_THE_WINNER_H
// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
// Player 1 and player 2 take turns, with player 1 starting first.
// Both players start the game with a score of 0. At each turn, the player takes one of the numbers
// from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of
// the array by 1. The player adds the chosen number to their score.
// The game ends when there are no more elements in the array.
// Return true if Player 1 can win the game. If the scores of both players are equal,
// then player 1 is still the winner, and you should also return true.
// You may assume that both players are playing optimally.
#include <vector>
#include <concepts>


template<typename T>
requires std::is_arithmetic_v<T>
T max_difference(const std::vector<T> &array, int left, int right)
{
	if (left == right)
		return array[left];

	T score_left = array[left] - max_difference(array, left + 1, right);
	T score_right = array[right] - max_difference(array, left, right - 1);
	return std::max(score_right, score_left);
}

template<typename T>
requires std::is_arithmetic_v<T>
bool predict_the_winner_recursion(const std::vector<T> &array)
{
	int n = array.size();
	return max_difference(array, 0, n - 1) >= 0;
}

template<typename T>
requires std::is_arithmetic_v<T>
T max_difference_top_down(const std::vector<T> &array, int left, int right, std::vector<std::vector<T>> &memo)
{
	if (memo[left][right] != T{-1})
		return memo[left][right];
	if (left == right)
		return array[left];

	T score_left = array[left] - max_difference_top_down(array, left + 1, right, memo);
	T score_right = array[right] - max_difference_top_down(array, left, right - 1, memo);
	memo[left][right] = std::max(score_right, score_left);
	return memo[left][right];
}

template<typename T>
requires std::is_arithmetic_v<T>
bool predict_the_winner_top_down(const std::vector<T> &array)
{
	int n = array.size();
	std::vector<std::vector<T>> memo(n, std::vector<T>(n, T{-1}));
	return max_difference_top_down(array, 0, n - 1, memo) >= 0;
}

template<typename T>
requires std::is_arithmetic_v<T>
bool predict_the_winner_bottom_up(const std::vector<T> &array)
{
	int n = array.size();
	std::vector<std::vector<T>> dp(n, std::vector<T>(n));
	for (int i{}; i < n; ++i)
		dp[i][i] = array[i];
	for (int index_diff = 1; index_diff < n; ++index_diff) {
		for (int left{}; left < n - index_diff; ++left) {
			int right = left + index_diff;
			dp[left][right] = std::max(array[left] - dp[left + 1][right], array[right] - dp[left][right - 1]);
		}
	}
	return dp[0][n - 1] >= 0;
}

template<typename T>
requires std::is_arithmetic_v<T>
bool predict_the_winner_optimized(const std::vector<T> &array)
{
	int n = array.size();
	std::vector<T> dp(array);
	for (int index_diff = 1; index_diff < n; ++index_diff) {
		for (int left{}; left < n - index_diff; ++left) {
			int right = left + index_diff;
			dp[left][right] = std::max(array[left] - dp[left + 1], array[right] - dp[left]);
		}
	}
	return dp[0] >= 0;
}


#endif //PREDICT_THE_WINNER_H
