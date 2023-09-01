//
// Created by andreas on 01.09.23.
//

#ifndef COUNTING_BITS_H
#define COUNTING_BITS_H
// Given an integer n, return an array 'result' of length n + 1 such that for each j (0 <= j <= n), result[j]
// is the number of 1's in the binary representation of j.
#include<vector>
std::vector<int> counting_bits(int n)
{
	std::vector<int> result(n + 1);
	result[0] = 0;
	for (int j{1}; j <= n; ++j) {
		result[j] = result[j >> 1] + (j & 1);
	}
	return result;
}
#endif //COUNTING_BITS_H
