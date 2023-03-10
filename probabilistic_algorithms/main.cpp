#include <iostream>
#include "reservoir_sampling.h"

int main() {
	std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int k = 5;
	std::vector<int> res = reservoir_sampling( nums, k);
	for (int num : res) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return 0;
}
