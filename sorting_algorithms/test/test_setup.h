//
// Created by andreas on 01.03.23.
//

#ifndef TEST_SETUP_H
#define TEST_SETUP_H
#include <random>
#include <array>
#include <vector>
#include "gtest/gtest.h"
class SetupSortingTests: public testing::Test
{
public:
	explicit SetupSortingTests()
		: random_engine_{std::random_device{}()}
	{
	}
	static constexpr int two_to_the_power_of_10{1024};
	static constexpr int two_to_the_power_of_11{2048};
	static constexpr int two_to_the_power_of_7{128};
	static bool compare_pointers(const int *a, const int *b)
	{
		return *a < *b;
	}

	std::vector<int> get_N_random_number_vector(const int lower_bound, const int upper_bound, const size_t size)
	{
		int_distribution_ = std::uniform_int_distribution{lower_bound, upper_bound};
		std::vector<int> result;
		for (size_t i{}; i < size; ++i) {
			result.push_back(int_distribution_(random_engine_));
		}
		return result;
	}

	std::vector<int *> get_N_random_number_vector_of_pointers(const int lower_bound,
															  const int upper_bound,
															  const size_t size)
	{
		int_distribution_ = std::uniform_int_distribution{lower_bound, upper_bound};
		std::vector<int *> result;
		for (size_t i{}; i < size; ++i) {
			int *p = new int(int_distribution_(random_engine_));
			result.push_back(p);
		}
		return result;
	}

	template<size_t size>
	std::array<int, size> get_N_random_number_array(const int lower_bound, const int upper_bound)
	{
		int_distribution_ = std::uniform_int_distribution{lower_bound, upper_bound};
		std::array<int, size> result;
		for (size_t i{}; i < size; ++i) {
			result[i] = int_distribution_(random_engine_);
		}
		return result;
	}
	std::string generate_random_string(const size_t length)
	{
		static const char characters[] =
			"0123456789!?;.'#$%^&*()[]{}"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		static const int number_of_characters = sizeof(characters) - 1;
		std::string result(length, '\0');
		std::generate_n(result.begin(), length, [&]()
		{
			return characters[std::uniform_int_distribution<>(0, number_of_characters - 1)(random_engine_)];
		});
		return result;
	}

private:
	std::mt19937 random_engine_;
	std::uniform_int_distribution<int> int_distribution_;
};
#endif //TEST_SETUP_H
