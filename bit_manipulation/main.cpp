#include <iostream>
#include "basic_bit_operations.h"

int main()
{
	int x = 1 << 4;
	int bit_position = 2;
	std::cout << has_bit<int8_t,32>(x, bit_position) << std::endl;
	return 0;
}
