//
// Created by andreas on 25.04.23.
//
#include "gtest/gtest.h"
#include "heaps/smallest_number_in_infinite_set.h"

TEST(SmallestNumberInInfiniteSet, just_pop)
{
	constexpr int initial_value = 1;
	constexpr int final_value = 10000;
	auto set = SmallestPositiveInfiniteSet(initial_value);
	for (int expected_value{initial_value}; expected_value <= final_value; ++expected_value) {
		EXPECT_EQ(expected_value, set.pop());
	}
}

TEST(SmallestNumberInInfiniteSet, add_back_then_pop)
{
	constexpr int initial_value = 1;
	constexpr int final_value = 10000;
	auto set = SmallestPositiveInfiniteSet(initial_value);
	for (int expected_value{initial_value}; expected_value <= final_value; ++expected_value) {
		set.add_back(expected_value);
		EXPECT_EQ(expected_value, set.pop());
	}
}

TEST(SmallestNumberInInfiniteSet, pop_then_add_back_then_pop)
{
	constexpr int initial_value = 1;
	constexpr int final_value = 10000;
	auto set = SmallestPositiveInfiniteSet(initial_value);
	for (int expected_value{initial_value}; expected_value <= final_value; ++expected_value) {
		EXPECT_EQ(expected_value, set.pop());
		set.add_back(expected_value);
		EXPECT_EQ(expected_value, set.pop());
	}
}

TEST(SmallestNumberInInfiniteSet, poo_pop_then_add_back_then_pop)
{
	constexpr int initial_value = 1;
	constexpr int final_value = 10000;
	auto set = SmallestPositiveInfiniteSet(initial_value);
	for (int expected_value{initial_value}; expected_value <= final_value; ++expected_value) {
		EXPECT_EQ(expected_value, set.pop());
	}
	std::vector<int> expected_values;
	int factor{1};
	for (int i{1}; i < 20; i++) {
		int expected_value = i * factor++;
		expected_values.push_back(expected_value);
		set.add_back(expected_value);
	}

	for (const auto expected_value: expected_values) {
		EXPECT_EQ(expected_value, set.pop());
	}

}