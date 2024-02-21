//
// Created by andreas on 21.02.24.
//

#ifndef BITWISE_AND_NUMBERS_IN_RANGE_H
#define BITWISE_AND_NUMBERS_IN_RANGE_H
// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
int range_bitwise_and(int left, int right)
{
	int shift{};
	// Find common prefix aka shift to the right until 'left' and 'right' are equal.
	while(left < right)
	{
		left>>=1;
		right>>=1;
		shift++;
	}
	return left << shift;
}
#endif //BITWISE_AND_NUMBERS_IN_RANGE_H
