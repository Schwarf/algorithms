#include <algorithm>
#include <iostream>
#include "merge_sort.h"

int main() {
	std::array<int, 4> h{7,1,6,4};
	merge_sort(h);
	for(const auto & element: h)
		std::cout << element << std::endl;
	return 0;
}