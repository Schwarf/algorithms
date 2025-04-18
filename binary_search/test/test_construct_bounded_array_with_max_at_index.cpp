//
// Created by andreas on 08.03.24.
//

#include "gtest/gtest.h"
#include "../construct_bounded_array_with_max_at_index.h"

TEST(TestConstructBoundedArrayWithMaxAtINdex, simple1)
{
	constexpr int array_size{4};
	constexpr int index{2};
	constexpr int max_sum{6};
	constexpr int expected_result{2};
	EXPECT_EQ(expected_result, max_value_from_constructed_array(array_size, index, max_sum));
}

TEST(TestConstructBoundedArrayWithMaxAtINdex, simple2)
{
	constexpr int array_size{3};
	constexpr int index{2};
	constexpr int max_sum{3};
	constexpr int expected_result{1};
	EXPECT_EQ(expected_result, max_value_from_constructed_array(array_size, index, max_sum));
}

TEST(TestConstructBoundedArrayWithMaxAtINdex, simple3)
{
	constexpr int array_size{15};
	constexpr int index{9};
	constexpr int max_sum{182};
	constexpr int expected_result{16};
	EXPECT_EQ(expected_result, max_value_from_constructed_array(array_size, index, max_sum));
}


TEST(TestConstructBoundedArrayWithMaxAtINdex, complex1)
{
	constexpr int array_size{9801};
	constexpr int index{8469};
	constexpr int max_sum{439132987};
	constexpr int expected_result{48554};
	EXPECT_EQ(expected_result, max_value_from_constructed_array(array_size, index, max_sum));
}
