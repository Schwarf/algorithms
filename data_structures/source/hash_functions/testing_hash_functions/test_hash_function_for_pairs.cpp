//
// Created by andreas on 16.07.23.
//
#include <random>
#include "gtest/gtest.h"
#include "hash_function_for_pairs.h"
#include "uniformity_of_pair_hash_functions.h"

TEST(TestUniformityOfPairHashes, integer_integer_pairs_commutative)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<size_t> distribution(1, 1000000000);
	std::vector<std::pair<int, int>> input;
	constexpr int number_of_samples = 1000000;
	constexpr int number_of_buckets = 1000;
	for (int i{}; i < number_of_samples; ++i) {
		auto first = distribution(generator);
		auto second = distribution(generator);
		input.emplace_back(first, second);
	}
	auto test =
		UniformityOfPairHashFunction<decltype(commutative_pair_hash<int, int>()), int, int>::compute_chi_square_value(
			commutative_pair_hash<int, int>(),
			input,
			number_of_buckets);
	constexpr double chi_square{1074.3};
	std::cout << test << std::endl;
	EXPECT_TRUE(test < chi_square);
}

TEST(TestUniformityOfPairHashes, integer_integer_pairs_non_commutative)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<size_t> distribution(1, 1000000000);
	std::vector<std::pair<int, int>> input;
	constexpr int number_of_samples = 1000000;
	constexpr int number_of_buckets = 1000;
	for (int i{}; i < number_of_samples; ++i) {
		auto first = distribution(generator);
		auto second = distribution(generator);
		input.emplace_back(first, second);
	}
	auto test =
		UniformityOfPairHashFunction<decltype(non_commutative_pair_hash<int, int>()),
									 int,
									 int>::compute_chi_square_value(
			non_commutative_pair_hash<int, int>(),
			input,
			number_of_buckets);
	constexpr double chi_square{1074.3};
	std::cout << test << std::endl;
	EXPECT_TRUE(test < chi_square);
}