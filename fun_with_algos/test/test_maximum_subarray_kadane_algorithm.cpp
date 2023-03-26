//
// Created by andreas on 26.03.23.
//

#ifndef TEST_MAXIMUM_SUBARRAY_KADANE_ALGORITHM_CPP
#define TEST_MAXIMUM_SUBARRAY_KADANE_ALGORITHM_CPP
#include "gtest/gtest.h"
#include "./../maximum_subarray_kadane_algorithm.h"

TEST(KadaneAlgorithm, simple1)
{
	std::vector<float> input {1.f, -2.4f, 5.0f, -19.f, 28.f, -1.919f, 2.1712f};
	float expected_result{28.2522};
	auto minimum = std::numeric_limits<float>::lowest();
	EXPECT_EQ(maximum_subarray_kadane_algorithm(input, minimum), expected_result);
}

TEST(KadaneAlgorithm, simple2)
{
	std::vector<int> input {12};
	int expected_result{12};
	auto minimum = std::numeric_limits<int>::lowest();
	EXPECT_EQ(maximum_subarray_kadane_algorithm(input, minimum), expected_result);
}


TEST(KadaneAlgorithm, no_element)
{
	std::vector<int> input {};
	auto minimum = std::numeric_limits<int>::lowest();
	int expected_result{minimum};
	EXPECT_EQ(maximum_subarray_kadane_algorithm(input, minimum), expected_result);
}

#endif //TEST_MAXIMUM_SUBARRAY_KADANE_ALGORITHM_CPP
