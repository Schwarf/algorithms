#include <iostream>
#include <array>
#include "reservoir_sampling.h"
#include "held_karp_algorithm.h"
#include "simulated_annealing.h"
#include "simulated_annealing_full_templated.h"
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
		std::cout << simulated_annealing_algorithm(cities, compute_tour_length<int, std::vector, std::vector>,
												   perturbation<int, std::vector, std::vector>, 1000.0, 0.9999, 1.0)
				  << std::endl;
		i--;
	}
}
