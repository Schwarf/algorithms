//
// Created by andreas on 20.09.22.
//
#include <iostream>

bool has_bit(int number, int bit_position)
{
	return (number & (1 << bit_position)) != 0;
}

// works only for 32-bit integers
int number_of_needed_flips_32bit(int number1, int number2)
{
	int bit_max_shift =32;
	int needed_flips{};
	for(int bit {}; bit < bit_max_shift; ++bit)
	{
		int bit_number1 = number1 & (1 << bit);
		int bit_number2 = number2 & (1 << bit);
		if(bit_number1 != bit_number2)
			needed_flips++;
	}
	return needed_flips;
}

template <typename T>
int number_of_needed_flips(T number1, T number2)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	auto xor_ed = number1 ^ number2;
	int needed_flips{};
	while(xor_ed !=0)
	{
		needed_flips += (xor_ed & 1);
		xor_ed >>= 1;
	}
	return needed_flips;
}


int main()
{
	std::cout << number_of_needed_flips(29, 15) << std::endl;

	std::cout << number_of_needed_flips(2843821094382099, 1423784902148092348) << std::endl;
}