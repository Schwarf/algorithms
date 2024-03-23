//
// Created by andreas on 16.07.23.
//
#include <random>
#include "gtest/gtest.h"
#include "./../hash_function_for_pairs.h"
#include "uniformity_of_pair_hash_functions.h"

TEST(TestUniformityOfPairHashes, integer_integer_pairs_commutative)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	constexpr int lower_bound{1};
	constexpr int upper_bound{1000000000};
	std::uniform_int_distribution<int> distribution(lower_bound, upper_bound);
	std::vector<std::pair<int, int>> input;
	constexpr int number_of_samples{1000000};
	constexpr int number_of_buckets{1000};
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
	// 999 degrees of freedom = buckets -1
	constexpr double chi_square{1074.3};
	std::cout << test << std::endl;
	EXPECT_TRUE(test < chi_square);
}

TEST(TestUniformityOfPairHashes, integer_integer_pairs_non_commutative)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	constexpr int lower_bound{1};
	constexpr int upper_bound{1000000000};
	std::uniform_int_distribution<int> distribution(lower_bound, upper_bound);
	std::vector<std::pair<int, int>> input;
	constexpr int number_of_samples{1000000};
	constexpr int number_of_buckets{1000};
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

TEST(TestUniformityOfPairHashes, integer_double_pairs_commutative)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	constexpr int int_lower_bound{1};
	constexpr int int_upper_bound{1000000000};
	constexpr double double_lower_bound{0.0};
	constexpr double double_upper_bound{1.0};
	std::uniform_int_distribution<int> int_distribution(int_lower_bound, int_upper_bound);
	std::uniform_real_distribution<double> double_distribution(double_lower_bound, double_upper_bound);
	std::vector<std::pair<int, double>> input;
	constexpr int number_of_samples{1000000};
	constexpr int number_of_buckets{1000};
	for (int i{}; i < number_of_samples; ++i) {
		auto first = int_distribution(generator);
		auto second = double_distribution(generator);
		input.emplace_back(first, second);
	}
	auto test =
		UniformityOfPairHashFunction<decltype(commutative_pair_hash<int, double>()),
									 int,
									 double>::compute_chi_square_value(
			commutative_pair_hash<int, double>(),
			input,
			number_of_buckets);
	constexpr double chi_square{1074.3};
	std::cout << test << std::endl;
	EXPECT_TRUE(test < chi_square);
}


TEST(TestUniformityOfPairHashes, integer_double_pairs_non_commutative)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	constexpr int int_lower_bound{1};
	constexpr int int_upper_bound{1000000000};
	constexpr double double_lower_bound{0.0};
	constexpr double double_upper_bound{1.0};
	std::uniform_int_distribution<int> int_distribution(int_lower_bound, int_upper_bound);
	std::uniform_real_distribution<double> double_distribution(double_lower_bound, double_upper_bound);
	std::vector<std::pair<int, double>> input;
	constexpr int number_of_samples{1000000};
	constexpr int number_of_buckets{1000};
	for (int i{}; i < number_of_samples; ++i) {
		auto first = int_distribution(generator);
		auto second = double_distribution(generator);
		input.emplace_back(first, second);
	}
	auto test =
		UniformityOfPairHashFunction<decltype(non_commutative_pair_hash<int, double>()),
									 int,
									 double>::compute_chi_square_value(
			non_commutative_pair_hash<int, double>(),
			input,
			number_of_buckets);
	constexpr double chi_square{1074.3};
	std::cout << test << std::endl;
	EXPECT_TRUE(test < chi_square);
}
