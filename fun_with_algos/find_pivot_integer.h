
#ifndef FIND_PIVOT_INTEGER_H
#define FIND_PIVOT_INTEGER_H
// Given a positive integer n, find the pivot integer x such that:
// The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
// Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at
// most one pivot index for the given input.


#include <cmath>
// O(N) runtime complexity
int pivot_integer_linear(int n)
{
	int max{-1};
	for(int i{1}; i <= n; ++i )
	{
		int left = i*(i+1)/2;
		int right = n*(n+1)/2 - i*(i-1)/2;
		if(right > 0 && left == right)
		{
			max = i;
		}
	}
	return max;
}

// O(lob N) runtime complexity
int pivot_integer_logarithmic(int n)
{
	int left{1};
	int right{n};
	int total = n*(n+1)/2;
	while(left < right)
	{
		int mid = (left+right)/2;
		if(mid*mid - total < 0)
		{
			left = mid +1;
		}
		else
			right = mid;
	}
	if(left *left - total == 0)
		return left;
	return -1;
}

// O(1)
// x(x+1)/2 = n*(n+1)/2 - (x*(x-1))/2
// --> x = sqrt(n*(n+1)/2)
int pivot_integer_math(int n) {
	const int sum = (n * (n + 1) / 2);
	const int pivot = std::sqrt(sum);
	return pivot * pivot == sum ? pivot : -1;
}

#endif //FIND_PIVOT_INTEGER_H
