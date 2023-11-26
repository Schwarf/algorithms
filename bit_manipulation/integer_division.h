//
// Created by andreas on 26.11.23.
//

#ifndef INTEGER_DIVISION_H
#define INTEGER_DIVISION_H
// Write a function to perform integer division without using either the / or * operators. Find a fast way to do it.
#include<concepts>
#include <stdexcept>

template <typename T>
requires std::is_signed_v<T>
T integer_division(T dividend, T divisor)
{
	if (divisor == 0) {
		throw std::overflow_error("Division by zero.");
	}
	else if (dividend == std::numeric_limits<T>::min() && divisor == -1) {
		// Handle overflow.
		return std::numeric_limits<T>::max();
	}
	T sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	using unsigned_T = typename std::make_unsigned<T>::type;
	unsigned_T temp_dividend = std::abs(static_cast<long long>(dividend));
	unsigned_T temp_divisor = std::abs(static_cast<long long>(divisor));
	unsigned_T result{};

	int bit_shift = std::numeric_limits<T>::digits - 1;  // Use digits to support other integer sizes

	while (temp_dividend >= temp_divisor) {
		// Find the largest double of the divisor that fits into the dividend.
		while ((temp_divisor << bit_shift) > temp_dividend || (temp_divisor << bit_shift) == 0) {
			bit_shift--;
		}

		// Add the number of times we could double the divisor.
		result += 1ULL << bit_shift;

		// Subtract the found multiple from the dividend.
		temp_dividend -= temp_divisor << bit_shift;
	}

	// Apply the sign to the result and cast it back to T.
	return static_cast<T>(result) * sign;
}
#endif //INTEGER_DIVISION_H
