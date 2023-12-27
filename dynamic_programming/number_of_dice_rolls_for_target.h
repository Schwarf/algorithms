//
// Created by andreas on 27.12.23.
//

#ifndef NUMBER_OF_DICE_ROLLS_FOR_TARGET_H
#define NUMBER_OF_DICE_ROLLS_FOR_TARGET_H
#include <vector>
// You have n dice, and each die has k faces numbered from 1 to k.
// Given three integers n, k, and target, return the number of possible ways (out of the k^n total ways)
// to roll the dice, so the sum of the face-up numbers equals target.
// Since the answer may be too large, return it modulo 109 + 7.

int number_of_dice_rolls_recursive(int max_number_of_dice, int dice_max_value, int target)
{
	if (max_number_of_dice == 0 && target == 0)
		return 1;
	if (target < 0 || max_number_of_dice == 0)
		return 0;
	int sum{};
	for (int i{1}; i <= dice_max_value; ++i) {
		sum += number_of_dice_rolls_recursive(max_number_of_dice - 1, dice_max_value, target - i);
	}
	return sum;

}

int number_of_dice_rolls_bottom_up(int max_number_of_dice, int dice_max_value, int target)
{
	int MOD = 1000000007;
	std::vector<std::vector<int>> dp(max_number_of_dice + 1, std::vector<int>(target + 1, 0));
	dp[0][0] = 1;
	for (int number_of_dice{1}; number_of_dice <= max_number_of_dice; number_of_dice++) {
		for (int value{1}; value <= target; ++value) {
			for (int face_value{1}; face_value <= dice_max_value; face_value++) {
				if (value >= face_value)
					dp[number_of_dice][value] =
						(dp[number_of_dice][value] + dp[number_of_dice - 1][value - face_value]) % MOD;
			}
		}
	}
	return dp[max_number_of_dice][target];
}

#endif //NUMBER_OF_DICE_ROLLS_FOR_TARGET_H
