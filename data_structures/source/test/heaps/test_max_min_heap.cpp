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
	template<typename T>
	static inline std::pair<std::vector<T>, std::vector<T>> get_random_n_numbers(int n)
	{
		if (n < 1)
			return std::make_pair(std::vector<T>(), std::vector<T>());
		int lower_bound{};
		int upper_bound = 10 * n;
		auto int_distribution_ = std::uniform_int_distribution<int>(lower_bound, upper_bound);
		std::vector<T> input{};
		std::vector<T> output{};
		std::random_device device;
		auto generator = std::mt19937(device());
		for (int i{}; i < n; ++i) {
			auto value = int_distribution_(generator);
			input.push_back(static_cast<T>(value));
			output.push_back(static_cast<T>(value));
		}
		std::sort(output.begin(), output.end());

		return std::make_pair(input, output);
	}

};


TEST_F(SetupMaxMinHeap, TestMinAndMaxSmallSequence)
{
	constexpr int number_of_elements{100};
	auto [input, output] = get_random_n_numbers<int>(number_of_elements);
	auto max_min_heap = MaxMinHeap<int>();
	for (const auto &element: input) {
		max_min_heap.push(element);
	}
	EXPECT_EQ(max_min_heap.min(), output.front());
	EXPECT_EQ(max_min_heap.max(), output.back());
}

TEST_F(SetupMaxMinHeap, TestPopMinSmallSequence)
{
	constexpr int number_of_elements{100};
	auto [input, output] = get_random_n_numbers<double>(number_of_elements);
	auto max_min_heap = MaxMinHeap<double>();
	for (const auto &element: input) {
		max_min_heap.push(element);
	}
	for (int i{}; i < number_of_elements / 5; ++i) {
		EXPECT_EQ(max_min_heap.min(), output[i]);
		max_min_heap.pop_min();
	}
}
