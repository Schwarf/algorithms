//
// Created by andreas on 19.02.22.
//

#ifndef UNIFORMITY_OF_HASH_FUNCTIONS_H
#define UNIFORMITY_OF_HASH_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <type_traits>

#include <boost/math/distributions/chi_squared.hpp>

#include "./../i_hash_function_for_strings.h"

template<size_t hash_table_size>
class UniformityOfHashFunctions
{
public:
	explicit UniformityOfHashFunctions()
	{
		hashes_ = std::vector<double>(hash_table_size, 0);
		open_read_file_();
	}

	void test(IHashFunction &hash_function)
	{

		double
			equal_distribution_expectation = static_cast<double>(words_.size()) / static_cast<double>(hash_table_size);
		size_t hash_value{};
		for (const auto &word: words_) {
			hash_value = hash_function.hash(word);
			hashes_.at(hash_value) += 1.0;
		}
		double sum{};
		for (const auto &hash_sum_element: hashes_) {
			sum += (equal_distribution_expectation - hash_sum_element)
				* (equal_distribution_expectation - hash_sum_element)
				/ equal_distribution_expectation;
		}
		std::cout << hash_table_size << std::endl;
		auto chi_squared = boost::math::chi_squared(static_cast<double> (hash_table_size - 1));
		double probability_hashes_are_uniformly_distributed = boost::math::cdf(chi_squared, sum);
		std::cout << "For the prime number: " << std::to_string(hash_function.prime_number()) << std::endl;
		std::cout << "the probability that the distribution is NOT derived from the uniform-distribution is given as :"
				  << probability_hashes_are_uniformly_distributed << std::endl;

	}

private:
	void open_read_file_()
	{
		datafile_.open(file_name_, std::ios::in);
		// We want to compute the hash of the sum-of-all-characters of a word in the data file.
		// Since the words in the data file contain characters that are represented by a negative char value
		// we need to project all chars to unsigned chars.
		// We ar doing that using std::make_unsigned<char>::type
		if (datafile_.is_open()) {
			std::string word_string;
			while (std::getline(datafile_, word_string)) {
				words_.push_back(word_string);
			}
		}
	}
	std::string file_name_{"./../hash_functions/testing_hash_functions/test_data.txt"};
	std::fstream datafile_{};
	std::vector<std::string> words_;
	std::vector<double> hashes_;
};


#endif //UNIFORMITY_OF_HASH_FUNCTIONS_H
