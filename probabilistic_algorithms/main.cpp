#include <iostream>
#include <array>
#include "reservoir_sampling.h"
#include "held_karp_algorithm.h"
#include "simulated_annealing.h"
int main()
{

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
	//std::cout << held_karp_algorithm(cities);
	double initial_temperature{100.0};
	double cooling_rate{0.95};
	double minimal_temperature{0.1};
	std::cout << simulated_annealing(cities, initial_temperature, cooling_rate, minimal_temperature) << std::endl;

}
