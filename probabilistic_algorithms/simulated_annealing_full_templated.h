//
// Created by andreas on 12.03.23.
//

#ifndef SIMULATED_ANNEALING_FULL_TEMPLATED_H
#define SIMULATED_ANNEALING_FULL_TEMPLATED_H
#include <random>
#include <algorithm>
#include "used_concepts.h"


template<typename T, typename ObjectFunctionType, typename PerturbationClass,
	template<typename...> class ContainerType,
	template<typename...> class InnerContainerType>
requires ContainerTypeTemplate<T, ContainerType, InnerContainerType>
	&& PerturbationFunctor<PerturbationClass, T, ContainerType, InnerContainerType>
	&& ObjectFunctionFunctor<ObjectFunctionType, T, ContainerType, InnerContainerType>
double simulated_annealing_algorithm(ContainerType<InnerContainerType<T>> &container,
									 ObjectFunctionType object_function,
									 PerturbationClass perturbation_function,
									 double initial_temperature,
									 double cooling_rate,
									 double minimal_temperature)
{
	std::mt19937 random_generator(std::random_device{}());
	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	auto current_value = object_function(container);
	double temperature = initial_temperature;
	while (temperature > minimal_temperature) {
		perturbation_function(container, random_generator);
		double new_value = object_function(container);
		double delta = new_value - current_value;
		if (delta < 0 || std::exp(-delta / temperature) > distribution(random_generator)) {
			current_value = new_value;
		}
		else
			perturbation_function.undo(container);
		temperature *= cooling_rate;
	}
	return current_value;
}

#endif //SIMULATED_ANNEALING_FULL_TEMPLATED_H
