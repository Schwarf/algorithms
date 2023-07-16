//
// Created by andreas on 15.07.23.
//

#ifndef TEST_UNIFORMITY_OF_PAIR_HASH_FUNCTIONS_H
#define TEST_UNIFORMITY_OF_PAIR_HASH_FUNCTIONS_H

#include <vector>
#include <unordered_map>
template<typename Functor, typename FirstType, typename SecondType>
concept PairHashFunction = requires(Functor functor, const std::pair<FirstType, SecondType> &argument)
{
	{ functor(argument) } -> std::same_as<std::size_t>;
};

template<typename HashFunction, typename FirstType, typename SecondType>
requires PairHashFunction<HashFunction, FirstType, SecondType>
double test_uniformity_of_pair_hash_functions(HashFunction hash_function,
											  const std::vector<std::pair<FirstType, SecondType>> &pairs,
											  int number_of_buckets)
{
	std::unordered_map<int, int> frequency;
	for (const auto &pair: pairs) {
		int bucket = hash_function(pair) % number_of_buckets;
		frequency[bucket]++;
	}
	auto expected_frequency = static_cast<double>(pairs.size()) / number_of_buckets;
	double chi_square_value{};
	for (const auto &[key, value]: frequency) {
		auto difference = static_cast<double>(value) - expected_frequency;
		chi_square_value += difference * difference / expected_frequency;
	}
	return chi_square_value;
}

#endif //TEST_UNIFORMITY_OF_PAIR_HASH_FUNCTIONS_H
