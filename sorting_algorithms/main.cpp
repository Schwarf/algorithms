#include <iostream>
#include <vector>
#include <array>
#include "quick_sort.h"
int main()
{
	//std::array<int, 8> test{100,1,2,38,4,56,8,5};
	std::vector<int> test2{0, 2, 1, -1, 3, 5};
	quick_sort(test2);
	for(const auto & element: test2)
		std::cout << element << ", ";
	std::cout << std::endl;

	return 0;
}
