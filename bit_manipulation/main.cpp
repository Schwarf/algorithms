#include <iostream>
#include "basic_bit_operations.h"

int main()
{
	uint64_t h{1};
	uint64_t x = h << 63;
	int bit_position = 63;
	std::cout << has_bit<uint64_t, 63>(x, bit_position) << std::endl;
	return 0;
}
