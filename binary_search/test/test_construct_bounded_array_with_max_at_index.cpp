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
