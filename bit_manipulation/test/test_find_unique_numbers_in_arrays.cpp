//
// Created by andreas on 04.07.23.
//

#include "gtest/gtest.h"
#include "./../find_unique_number_in_arrays.h"

TEST(FindUniqueNumberInArray, find_in_array_of_pairs_one_element)
{
	std::vector<long long>input{1000000000};
	constexpr long long expected_result{1000000000};
	EXPECT_EQ(expected_result, find_unique_number_in_array_with_pairs(input));
}

TEST(FindUniqueNumberInArray, find_in_array_of_pairs_several_elements)
{
	std::vector<char>input{12,12,15,16,16,17,17,1,2,1,2};
	constexpr char expected_result{15};
	EXPECT_EQ(expected_result, find_unique_number_in_array_with_pairs(input));
}


TEST(FindUniqueNumberInArray, find_in_array_of_pairs_several_elements2)
{
	std::vector<int>input{1,2,3,4,5,6,7,7,6,5,4,3,2,1, -1};
	constexpr int expected_result{-1};
	EXPECT_EQ(expected_result, find_unique_number_in_array_with_pairs(input));
}


TEST(FindUniqueNumberInArray, find_in_array_of_triples_one_element)
{
	std::vector<long long>input{1000000000};
	constexpr long long expected_result{1000000000};
	EXPECT_EQ(expected_result, find_unique_number_in_array_with_triples(input));
}

TEST(FindUniqueNumberInArray, find_in_array_of_triples_several_elements)
{
	std::vector<char>input{12,12,15,16,16,17,17,1,2,1,2, 12,1,2,16,17};
	constexpr char expected_result{15};
	EXPECT_EQ(expected_result, find_unique_number_in_array_with_triples(input));
}


TEST(FindUniqueNumberInArray, find_in_array_of_triples_several_elements2)
{
	std::vector<int>input{1,2,3,4,5,6,7,7,6,5,4,3,2,1, 11, 7,6,5,4,3,2,1};
	constexpr int expected_result{11};
	EXPECT_EQ(expected_result, find_unique_number_in_array_with_triples(input));
}