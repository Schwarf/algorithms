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
	SetupSorting(){
		std::random_device random_device;
		std::mt19937_64 mersenne_generator(random_device());
		std::uniform_int_distribution<int64_t> uniform_distribution;
		size_t N = 10000;
		for(size_t index =0; index < N; ++index)
		{
			auto number = uniform_distribution(mersenne_generator);
			random_numbers.push_back(number);
			std_sorted_reference.push_back(number);
		}
		std::sort(std_sorted_reference.begin(), std_sorted_reference.end());
	}


protected:
	std::vector<int64_t> random_numbers;
	std::vector<int64_t> std_sorted_reference;
};

#endif //SORTING_SETUP_H
