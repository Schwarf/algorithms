//
// Created by andreas on 19.02.22.
//

#ifndef TEST_HASH_FUNCTIONS_H
#define TEST_HASH_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <type_traits>

#include <boost/math/distributions/chi_squared.hpp>

#include "./../i_hash_function.h"

template <size_t hash_table_size>
class TestHashFunctions
{
public:
	explicit TestHashFunctions()
	{
		hashes_ = std::vector<double>(hash_table_size, 0);
		open_read_file_();
	}

	size_t convert_string_to_hashable_value( const std::string & string, size_t prime_number)
	{
		size_t result{};
		size_t string_as_base_256_number = 256;
		for(size_t index = string.size(); index--;)
		{
			result = (result * string_as_base_256_number + string.at(index)) % prime_number;
		}
		return result;
	}

	void test(IHashFunction & hash_function)
	{

		double equal_distribution_expectation = static_cast<double>(words_.size()) / static_cast<double>(hash_table_size);
		size_t hash_value{};
		auto prime_number = hash_function.prime_number();
		for (const auto & word: words_) {
			hash_value = convert_string_to_hashable_value(word, prime_number);
			hashes_.at(hash_value) += 1.0;
		}
		double sum{};
		for (const auto & hash_sum_element: hashes_) {
			sum += (equal_distribution_expectation - hash_sum_element) * (equal_distribution_expectation - hash_sum_element)
				/ equal_distribution_expectation;
		}
		std::cout << hash_table_size << std::endl;
		auto chi_squared = boost::math::chi_squared(static_cast<double> (hash_table_size - 1));
		double probability_hashes_are_uniformly_distributed = boost::math::cdf(chi_squared, sum);
		std::cout << "For the prime number: " << std::to_string(hash_function.prime_number()) << std::endl;
		std::cout << "the probability that the distribution is NOT derived from the uniform-distribution is given as :" << probability_hashes_are_uniformly_distributed << std::endl;

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


#endif //TEST_HASH_FUNCTIONS_H
