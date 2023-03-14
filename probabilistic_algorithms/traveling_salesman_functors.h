//
// Created by andreas on 14.03.23.
//

#ifndef TRAVELING_SALESMAN_FUNCTORS_H
#define TRAVELING_SALESMAN_FUNCTORS_H
#include <random>
#include <algorithm>

template<typename T, template<typename...> class ContainerType,
	template<typename...> class InnerContainerType>
class TravelingSalesmanObjectFunction
{
public:
	double operator()(const ContainerType<InnerContainerType<T>> &container)
	{
		auto distance_function = [](const auto &container1, const auto &container2)
		{
			double distance{};
			for (size_t i{}; i < container1.size(); ++i) {
				double difference = container1[i] - container2[i];
				distance += difference * difference;
			}
			return std::sqrt(distance);
		};
		const auto number_of_elements = container.size();
		double tour_length{};
		for (size_t i{}; i < number_of_elements - 1; ++i)
			tour_length += distance_function(container[i], container[i + 1]);
		tour_length += distance_function(container[number_of_elements - 1], container[0]);
		return tour_length;
	}
};

template<typename T, template<typename...> class ContainerType,
	template<typename...> class InnerContainerType>
class TravelingSalesmanPerturbationFunction
{
public:
	void operator()(ContainerType<InnerContainerType<T>> &container,
					decltype(std::declval<std::mt19937>()) &random_generator)
	{
		std::uniform_int_distribution<int> distribution(0, container.size() - 1);
		index1_ = distribution(random_generator);
		index2_ = distribution(random_generator);
		std::swap(container[index1_], container[index2_]);
	}

	void undo(ContainerType<InnerContainerType<T>> &container)
	{
		std::swap(container[index1_], container[index2_]);
	}

private:
	size_t index1_{};
	size_t index2_{};
};

#endif //TRAVELING_SALESMAN_FUNCTORS_H
