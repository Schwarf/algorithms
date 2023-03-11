#include <iostream>
#include <array>
#include "reservoir_sampling.h"
#include "held_karp_algorithm.h"

int main() {

	std::vector<std::vector<int>> cities = {{0, 0},
											  {1, 1},
											  {2, 0},
											  {3, 2},
											  {4, 1},
											  {5, 3},
											  {6, 0},
											  {7, 2},
											  {27, -10},
											  {-6, -9}};
	std::cout << held_karp_algorithm(cities);

}
