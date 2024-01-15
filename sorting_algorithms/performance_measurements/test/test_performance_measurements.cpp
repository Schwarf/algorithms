//
// Created by andreas on 15.01.24.
//

#include "gtest/gtest.h"
#include "./../performance_measurement.h"
#include "./../../bubble_sort.h"

TEST(PerformanceMeasurement, simple1)
{
	std::vector<int>
		input
		{3, 1, 2, 1, 3, 14, 4, 6, 7, 25, 3, 63, 672, 5, 2, 2, 5, 637, 8, 436, 36, 26, 23, 35, 78, 57, 325, 31, 31, 1,
		 636, 36, 89, 46, 8, 852, 25, 25, 25, 2, 52, 52, 52, 3, 57, 57, 56, 35, 3, 53, 754, 76, 835, 5, 46, 57, 546, 5,
		 437, 54623, 5, 2436754, 75};
	auto performance_measurer = PerformanceMeasurement<int>();
	auto bubble_sort_func = bubble_sort<std::vector<int>>;
	constexpr int experiments{10000};
	for (int i{}; i < experiments; ++i) {
		auto copy_input = input;
		performance_measurer.measure_sort_performance(bubble_sort_func, copy_input);
	}
	auto results = performance_measurer.get_results();
	EXPECT_EQ(std::get<0>(results), experiments);
	std::cout << std::get<1>(results) << std::endl;
	std::cout << std::get<2>(results) << std::endl;
	std::cout << std::get<3>(results) << std::endl;
}