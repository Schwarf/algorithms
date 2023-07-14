//
// Created by andreas on 14.07.23.
//

#ifndef NTH_UGLY_NUMBER_H
#define NTH_UGLY_NUMBER_H
// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.

bool isUgly(int num)
{
	if (num == 1)
		return true;
	if (num % 2 == 0)
		return isUgly(num / 2);
	if (num % 3 == 0)
		return isUgly(num / 3);
	if (num % 5 == 0)
		return isUgly(num / 5);
	return false;
}

int nth_ugly_number_recursive(int n, int num = 1)
{
	if (n == 1)
		return num;
	int next = num + 1;
	while (!isUgly(next))
		next++;
	return nth_ugly_number_recursive(n - 1, next);
}


#endif //NTH_UGLY_NUMBER_H
