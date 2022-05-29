//
// Created by andreas on 29.05.22.
//

#include <bitset>
#include <iostream>


template <typename T, size_t bitset_size>
std::bitset<bitset_size> convert(T & value)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	return std::bitset<bitset_size>(value);

}

template <typename T>
bool has_bit(T number, int bit_position)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	return (number & (1 << bit_position)) != 0;
}

template <typename T>
void set_bit(T &number, int bit_position)
{
	static_assert(std::is_integral<T>::value, "Integral required.");

	number |= (1 << bit_position);
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
	std::cout << "Set 5 bit of 29."  << std::endl;
	set_bit<int>(x1, 5);
	std::cout << "Bit 5 of 29 (with 5th bit set) aka ("<< x1 << "=61) shall be set: " << has_bit<int>(x1, 5) << std::endl;
	std::cout << "Set 1 bit of 61."  << std::endl;
	set_bit<int>(x1, 1);
	std::cout << "Bit 2 of 61 (with 2nd bit set) aka ("<< x1 << "=63) shall be set: " << has_bit<int>(x1, 1) << std::endl;

	return 0;
}
