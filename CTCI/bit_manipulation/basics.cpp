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



int main()
{
	int x1{56};
	std::cout << convert<int, 6>(x1).to_string() << std::endl;
	return 0;
}
