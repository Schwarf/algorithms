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
	std::unordered_map<int, int> histogram;
	for (const auto &pair: pairs) {
		int bucket = hash_function(pair) % number_of_buckets;
		histogram[bucket]++;
	}
	auto expected_count = static_cast<double>(pairs.size()) / number_of_buckets;
	double chi_square{};
	for (const auto &[key, value]: histogram) {
		double difference = static_cast<double>(value) - expected_count;
		chi_square += difference * difference / expected_count;
	}
	return chi_square;
}

#endif //TEST_UNIFORMITY_OF_PAIR_HASH_FUNCTIONS_H
