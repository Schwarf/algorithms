//
// Created by andreas on 03.04.24.
//
#include "gtest/gtest.h"
#include "heaps/max_min_heap.h"
#include <random>
#include <utility>
class SetupMaxMinHeap: public testing::Test
{
public:
	static inline std::pair<std::vector<int>, std::vector<int>> get_random_n_numbers(int n)
	{
		if (n < 1)
			return std::make_pair(std::vector<int>(), std::vector<int>());
		int lower_bound{};
		int upper_bound = 10 * n;
		auto int_distribution_ = std::uniform_int_distribution<int>(lower_bound, upper_bound);
		std::vector<int> input{};
		std::vector<int> output{};
		std::random_device device;
		auto generator = std::mt19937(device());
		for (int i{}; i < n; ++i) {
			auto value = int_distribution_(generator);
			input.push_back(value);
			output.push_back(value);
		}
		std::sort(output.begin(), output.end());

		return std::make_pair(input, output);
	}

};


TEST_F(SetupMaxMinHeap, SmallSequence)
{
	auto [input, output] = get_random_n_numbers(100);
	auto max_min_heap = MaxMinHeap<int>();
	for (const auto &element: input) {
		std::cout << element << std::endl;
		max_min_heap.push(element);
	}
	EXPECT_EQ(max_min_heap.min(), output.front());
	EXPECT_EQ(max_min_heap.max(), output.back());
}