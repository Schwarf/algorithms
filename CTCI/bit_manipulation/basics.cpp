//
// Created by andreas on 29.05.22.
//

#include <bitset>
#include <iostream>
#include <type_traits>
#include <cmath>

int get_next_power_of_two(int number)
{
	number--;
	number |= number >> 1;
	number |= number >> 2;
	number |= number >> 4;
	number |= number >> 8;
	number |= number >> 16;
	number++;
    return number;
}

int find_complement(int num)
{
	int exponent = std::log2(num) + 1;
	for (int i = 0; i < exponent; i++) {
		num = num ^ (1 << i);
	}
	return num;
}

bool is_power_of_two(int number)
{
	return number > 0 && ((number & (number-1)) ==0);
}

bool is_power_of_three(int n)
{
	if (n <= 0)
		return false;
	// largest number in 32bit int that is a power of three is 3**int(math.log(2**31-1, 3))
	return 1162261467 % n == 0;
}

bool is_power_of_four(int number)
{
	// 5 in hexadecimal has the binary representation 0101. Since all powers of four have the pattern ...1010100 we
	// use this
	return number > 0 && ((number & (number-1)) ==0) && (number & 0x555555555);
}

template<typename T, size_t bitset_size>
std::bitset<bitset_size> convert(T &value)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	return std::bitset<bitset_size>(value);

}

template<typename T>
bool has_bit(T number, int bit_position)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	return (number & (1 << bit_position)) != 0;
}

template<typename T>
void set_bit(T &number, int bit_position)
{
	static_assert(std::is_integral<T>::value, "Integral required.");

	number |= (1 << bit_position);
}

template<typename T>
void clear_bit(T &number, int bit_position)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	int mask = ~(1 << bit_position);
	number &= mask;
}

template<typename T>
void clear_most_significant_bits_until(T &number, int bit_position)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	int mask = (1 << bit_position) -1;
	number &= mask;
}

template<typename T>
void clear_bits_from_zero_until(T &number, int bit_position)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	int mask = (-1 << (bit_position + 1));
	number &= mask;
}




int main()
{
	int x1{29};
	std::cout << convert<int, 6>(x1).to_string() << std::endl;
	std::cout << "Bit 5 of 29 shall be NOT set: " << has_bit<int>(x1, 5) << std::endl;
	std::cout << "Bit 3 of 29 shall be set: " << has_bit<int>(x1, 3) << std::endl;
	std::cout << "Bit 2 of 29 shall be set: " << has_bit<int>(x1, 2) << std::endl;
	std::cout << "Bit 1 of 29 shall be NOT set: " << has_bit<int>(x1, 1) << std::endl;
	std::cout << "Bit 0 of 29 shall be set: " << has_bit<int>(x1, 0) << std::endl;
	std::cout << "Set 5 bit of 29." << std::endl;
	set_bit<int>(x1, 5);
	std::cout << "Bit 5 of 29 (with 5th bit set) aka (" << x1 << "=61) shall be set: " << has_bit<int>(x1, 5)
			  << std::endl;
	std::cout << "Set 1 bit of 61." << std::endl;
	set_bit<int>(x1, 1);
	std::cout << "Bit 1 of 61 (with 2nd bit set) aka (" << x1 << "=63) shall be set: " << has_bit<int>(x1, 1)
			  << std::endl;
	clear_bit<int>(x1, 1);
	std::cout << "Bit 1 of 63 (with 2nd bit cleared) aka (" << x1 << "=61) shall be NOT set: " << has_bit<int>(x1, 1)
			  << std::endl;
	clear_most_significant_bits_until<int>(x1, 4);
	std::cout << "Bit 5 (and 4) cleared of 61 aka (" << x1 << "=13) shall be NOT set: " << has_bit<int>(x1, 5)
			  << std::endl;
	std::cout << "Bit 4 (and 5) cleared of 61 aka (" << x1 << "=13) shall be NOT set: " << has_bit<int>(x1, 4)
			  << std::endl;
	clear_bits_from_zero_until<int>(x1, 2);
	std::cout << "Bit 2 (and 1 and 0) cleared of 13 aka (" << x1 << "=8) shall be NOT set: " << has_bit<int>(x1, 2)
			  << std::endl;
	std::cout << "Bit 1 (and 2 and 0) cleared of 13 aka (" << x1 << "=8) shall be NOT set: " << has_bit<int>(x1, 1)
			  << std::endl;
	std::cout << "Bit 0 (and 1 and 2) cleared of 13 aka (" << x1 << "=8) shall be NOT set: " << has_bit<int>(x1, 1)
			  << std::endl;

	return 0;
}
