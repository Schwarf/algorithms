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
	auto held_karp_result = held_karp_algorithm(cities);
	std::cout << held_karp_result << std::endl;
	int i{10};
	std::cout << "------------------------------" << std::endl;
	while(i) {

		double initial_temperature{100.0};
		double cooling_rate{0.99};
		double minimal_temperature{0.1};
		auto approximate_result = simulated_annealing(cities, initial_temperature, cooling_rate, minimal_temperature);
		std::cout << approximate_result << std::endl;
		auto deviation = std::abs(1.0 - approximate_result/held_karp_result);
		std::cout << "Deviation is: " << deviation << std::endl;
		i--;
	}

}
