#include <iostream>
#include "binary_search.h"

int main()
{
	std::vector<int> test{1, 2, 3, 4, 5};
	std::cout << find(test, 1) << std::endl;
	std::cout << find(test, 7) << std::endl;
	std::cout << find(test, 0) << std::endl;
	return 0;
}
