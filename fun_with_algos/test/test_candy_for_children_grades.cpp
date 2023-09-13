//
// Created by andreas on 13.09.23.
//

#include "gtest/gtest.h"
#include "candy_for_children_grades.h"

TEST(CandyForChildrenGrades, simple1)
{
	const std::vector<short> grades{1, 0, 2};
	constexpr short expected_result{5};
	EXPECT_EQ(expected_result, total_candy(grades));
}
