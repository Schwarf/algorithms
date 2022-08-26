//
// Created by andreas on 26.08.22.
//
#include <cmath>
#include <algorithm>
#include <iostream>

int get_max_length(int number)
{
	int exponent = std::log2(number) + 1;
	std::cout << number << ", " << exponent << std::endl;
	int max_length{};
	int length{};
	for (int i{}; i < exponent; ++i) {
		bool set = (1 << i) & number;
		if (set)
			length++;
		else {
			max_length = std::max(max_length, length);
			length = 0;
		}
	}
	max_length = std::max(max_length, length);
	return max_length;
}

int get_max_length_with_one_flip(int number)
{
	bool flip = true;
	int exponent = std::log2(number) + 1;
	int max_length{};
	int length{};
	for (int i{}; i < exponent; ++i) {
		if ((1 << i) & number)
			length++;
		else if (flip) {
			length++;
			flip = false;
		}
		else {
			max_length = std::max(max_length, length);
			length = 0;
		}
	}
	return max_length;
}

int main()
{
//	int test = 1775;
	int test1 = 128 + 64 + 32 + 8 + 4 + 1;
//	std::cout << get_max_length(test) << std::endl;
//	std::cout << get_max_length_with_one_flip(test) << std::endl;

	std::cout << get_max_length(test1) << std::endl;
	std::cout << get_max_length_with_one_flip(test1) << std::endl;

}