//
// Created by andreas on 18.07.22.
//
#include <iostream>
#include <array>

constexpr int MaxN = 100;  // Maximum value of n

constexpr std::array<long long, 50> ComputeFibonacci()
{
	std::array<long long, 50> fibonacci{};
	fibonacci[0] = 0;
	fibonacci[1] = 1;

	for (int i = 2; i < 50; ++i) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	return fibonacci;
}

int main()
{
	constexpr int n = 50;  // Number of Fibonacci numbers to compute

	constexpr auto fibonacciNumbers = ComputeFibonacci();

	for (int i = 0; i < n; ++i) {
		std::cout << fibonacciNumbers[i] << " ";
	}

	return 0;
}