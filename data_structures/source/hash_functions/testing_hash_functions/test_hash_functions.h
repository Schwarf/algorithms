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


class TestHashFunctions
{
public:
	explicit TestHashFunctions();
	void test(IHashFunction & hash_funcion);
private:
	void open_read_file_();
	std::string file_name_{"/media/linux_data/projects/cpp/algorithms/data_structures/source/hash_functions/testing_hash_functions/test_data.txt"};
	std::fstream datafile_{};
	std::vector<size_t> words_;
};


#endif //TEST_HASH_FUNCTIONS_H
