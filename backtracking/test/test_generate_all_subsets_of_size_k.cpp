//
// Created by andreas on 01.08.23.
//

#include "gtest/gtest.h"
#include "generate_all_subsets_of_size_k.h"

TEST(GenerateSubsetsOfSizeK, simple1)
{
	constexpr unsigned short n{4};
	constexpr unsigned short k{2};
	const std::vector<std::vector<unsigned short>> expected_result{{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
	EXPECT_EQ(expected_result, generate_all_subsets_of_size_k(n,k));
}

TEST(GenerateSubsetsOfSizeK, simple2)
{
	constexpr unsigned int n{1};
	constexpr unsigned int k{1};
	const std::vector<std::vector<unsigned int>> expected_result{{1}};
	EXPECT_EQ(expected_result, generate_all_subsets_of_size_k(n,k));
}

TEST(GenerateSubsetsOfSizeK, simple3)
{
	constexpr unsigned int n{5};
	constexpr unsigned int k{3};
	const std::vector<std::vector<unsigned int>> expected_result {{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},{1,4,5},{2,3,4},{2,3,5},{2,4,5},{3,4,5}};
	EXPECT_EQ(expected_result, generate_all_subsets_of_size_k(n,k));
}

TEST(GenerateSubsetsOfSizeK, simple4)
{
	constexpr unsigned int n{4};
	constexpr unsigned int k{4};
	const std::vector<std::vector<unsigned int>> expected_result{{1,2,3,4}};
	EXPECT_EQ(expected_result, generate_all_subsets_of_size_k(n,k));
}


