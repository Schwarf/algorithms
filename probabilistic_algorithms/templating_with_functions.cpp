#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <numeric>
#include <cmath>

#include "used_concepts.h"

template<typename T, typename FunctionType,
	template<typename...> class ContainerType,
	template<typename...> class InnerContainerType>
requires ContainerTypeTemplate<T, ContainerType, InnerContainerType>
	&& std::invocable<FunctionType, InnerContainerType<T>, InnerContainerType<T>>
	&& ReturnTypeIsDouble<FunctionType, T, InnerContainerType>
double FunctionA(const ContainerType<InnerContainerType<T>> &container, FunctionType func)
{
	double result = 0.0;
	for (const auto &inner_container1: container) {
		for (const auto &inner_container2: container) {
			if (&inner_container1 == &inner_container2) {
				continue;
			}
			result += func(inner_container1, inner_container2);
		}
	}
	return result;
}

template<typename T, template<typename> class ContainerType>
double CalculateDistance(const ContainerType<T> &v1, const ContainerType<T> &v2)
{
	double sum = 0.0;
	for (std::size_t i = 0; i < v1.size(); ++i) {
		sum += std::pow(v1[i] - v2[i], 2);
	}
	return std::sqrt(sum);
}

int main()
{
	std::vector<std::vector<int>> v = {{2, 2}, {0, 0}};
	double result = FunctionA(v, CalculateDistance<int, std::vector>);
	std::cout << "Result: " << result << std::endl;
	return 0;
}

/*
#include <iostream>
#include <concepts>
#include <vector>

#include <concepts>
#include <type_traits>
#include <vector>

template <typename T, template <typename> typename CoordinateType, template <typename> typename InnerContainerType, typename FunctionType>
double FunctionA(const CoordinateType<InnerContainerType<T>>& container, FunctionType f) {
	double result{};
	for (const auto& innerContainer : container) {
		for (auto i = std::begin(innerContainer); i != std::end(innerContainer) - 1; ++i) {
			for (auto j = i + 1; j != std::end(innerContainer); ++j) {
				result += f(i, j);
			}
		}
	}
	return result;
}

template <typename I>
double FunctionB(const I& a, const I& b) {
	return static_cast<double>(*a) + static_cast<double>(*b);
}
int main() {
	std::vector<std::vector<int>> container{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	double sum = FunctionA(container, FunctionB<std::vector<int>::const_iterator>);
	std::cout << "Sum: " << sum << std::endl;
	return 0;
}


*/