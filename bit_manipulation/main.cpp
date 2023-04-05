#include <iostream>
#include "basic_bit_operations.h"

int main()
{
	uint32_t h{1};
	uint32_t x = h << 14;
	int bit_position = 41;
	//std::cout << has_bit(x, bit_position) << std::endl;
	int y{};
	set_bit(y, 3);
	std::cout << y << std::endl;
	return 0;

}
