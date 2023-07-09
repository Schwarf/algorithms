//
// Created by andreas on 26.03.23.
//

#ifndef TEST_MAXIMUM_SUBARRAY_KADANE_ALGORITHM_CPP
#define TEST_MAXIMUM_SUBARRAY_KADANE_ALGORITHM_CPP
#include <deque>
#include "gtest/gtest.h"
#include "../../dynamic_programming/maximum_subarray_kadane_algorithm.h"

TEST(KadaneAlgorithm, simple1)
{
	const std::vector<float> input {1.f, -2.4f, 5.0f, -19.f, 28.f, -1.919f, 2.1712f};
	constexpr float expected_result{28.2522};
	constexpr auto minimum = std::numeric_limits<float>::lowest();
	EXPECT_EQ(maximum_subarray_kadane_algorithm(input, minimum), expected_result);
}

TEST(KadaneAlgorithm, simple2)
{
	const std::vector<int> input {12};
	constexpr int expected_result{12};
	constexpr auto minimum = std::numeric_limits<int>::lowest();
	EXPECT_EQ(maximum_subarray_kadane_algorithm(input, minimum), expected_result);
}


TEST(KadaneAlgorithm, no_element)
{
	const std::vector<int> input {};
	constexpr auto minimum = std::numeric_limits<int>::lowest();
	EXPECT_EQ(maximum_subarray_kadane_algorithm(input, minimum), minimum);
}

TEST(KadaneAlgorithm, simple_array1)
{
	constexpr std::array<float, 7> input {1.f, -2.4f, 5.0f, -19.f, 28.f, -1.919f, 2.1712f};
	constexpr float expected_result{28.2522};
	constexpr auto minimum = std::numeric_limits<float>::lowest();
	EXPECT_EQ(maximum_subarray_kadane_algorithm(input, minimum), expected_result);
}


TEST(KadaneAlgorithm, no_array_element)
{
	constexpr std::array<float, 0> input {};
	constexpr auto minimum = std::numeric_limits<float>::lowest();
	EXPECT_EQ(maximum_subarray_kadane_algorithm(input, minimum), minimum);
}

TEST(KadaneAlgorithm, simple1_deque)
{
	const std::deque<float> input {1.f, -2.4f, 5.0f, -19.f, 28.f, -1.919f, 2.1712f};
	constexpr float expected_result{28.2522};
	constexpr auto minimum = std::numeric_limits<float>::lowest();
	EXPECT_EQ(maximum_subarray_kadane_algorithm(input, minimum), expected_result);
}

TEST(KadaneAlgorithm, simple2_deque)
{
	const std::deque<int> input {12};
	constexpr int expected_result{12};
	constexpr auto minimum = std::numeric_limits<int>::lowest();
	EXPECT_EQ(maximum_subarray_kadane_algorithm(input, minimum), expected_result);
}


#endif //TEST_MAXIMUM_SUBARRAY_KADANE_ALGORITHM_CPP
