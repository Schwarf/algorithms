//
// Created by andreas on 16.01.22.
//

#ifndef SORTING_SETUP_H
#define SORTING_SETUP_H
#include <random>
#include <algorithm>
class SetupSorting: public testing::Test
{
public:
	SetupSorting()
	{
		std::random_device random_device;
		std::mt19937_64 mersenne_generator(random_device());
		std::uniform_int_distribution<int64_t> uniform_distribution;
		size_t N = 5000;
		for (size_t index = 0; index < N; ++index) {
			auto number = uniform_distribution(mersenne_generator);
			random_numbers.push_back(number);
			std_sorted_reference.push_back(number);
		}
		std::sort(std_sorted_reference.begin(), std_sorted_reference.end());

		std::uniform_int_distribution<int64_t> uniform_distribution_in_range(lower_limit_, upper_limit_);
		size_t range_N = 3;
		for (size_t index = 0; index < range_N; ++index) {
			auto number = uniform_distribution_in_range(mersenne_generator);
			std_sorted_numbers_in_range.push_back(number);
		}
		std::sort(std_sorted_numbers_in_range.begin(), std_sorted_numbers_in_range.end());

	}


protected:
	std::vector<int64_t> random_numbers;
	std::vector<int64_t> std_sorted_reference;
	std::vector<int64_t> random_numbers_in_range;
	std::vector<int64_t> std_sorted_numbers_in_range;
	int64_t upper_limit_{1129};
	int64_t lower_limit_{-777};
};

#endif //SORTING_SETUP_H
