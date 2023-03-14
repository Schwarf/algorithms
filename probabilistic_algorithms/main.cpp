#include <iostream>
#include <array>
#include "reservoir_sampling.h"
#include "held_karp_algorithm.h"
#include "simulated_annealing.h"
#include "traveling_salesman_functors.h"
#include "simulated_annealing_full_templated.h"
int main()
{
	std::vector<std::vector<std::string>> bad = {{"asas", "asasre"},
												 {"afdgfdas", "ashdha"},
												 {"dgfadsas", "qewqrehsasre"}};


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

	std::vector<std::vector<double>> cities2 = {
		{82, 76}, {96, 44}, {50, 5}, {49, 8}, {13, 7}, {29, 89}, {58, 30}, {84, 39},
		{14, 61}, {2, 27}, {3, 89}, {56, 67}, {71, 91}, {80, 33}, {49, 92}, {70, 7},
		{66, 3}, {1, 44}, {88, 82}, {70, 88}
	};


	auto held_karp_result = held_karp_algorithm(cities2);
	std::cout << held_karp_result << std::endl;
	int i{10};
	std::cout << "------------------------------" << std::endl;
	auto perturbation_function =  TravelingSalesmanPerturbationFunction<int, std::vector, std::vector>();
	auto object_function = TravelingSalesmanObjectFunction<int, std::vector, std::vector>();
	while(i) {
		std::cout << simulated_annealing_algorithm(cities, object_function, perturbation_function, 1000.0, 0.9999, 1.0)
				  << std::endl;
		i--;
	}
}
