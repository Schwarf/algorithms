//
// Created by andreas on 22.11.22.
//
#include "gtest/gtest.h"
#include "./../perfect_square.h"


TEST(perfect_square, perfect_square_1)
{
	auto target{1};
	auto answer{1};
	EXPECT_EQ(answer, number_of_perfect_square_summands_needed(target));
}

TEST(perfect_square, perfect_square_12)
{
	auto target{12};
	auto answer{3};
	EXPECT_EQ(answer, number_of_perfect_square_summands_needed(target));
}


TEST(perfect_square, perfect_square_13)
{
	auto target{13};
	auto answer{2};
	EXPECT_EQ(answer, number_of_perfect_square_summands_needed(target));
}

TEST(perfect_square, perfect_square_1791)
{
	auto target{1791};
	auto answer{4};
	EXPECT_EQ(answer, number_of_perfect_square_summands_needed(target));
}

TEST(perfect_square, perfect_square_9974)
{
	auto target{9973};
	auto answer{4};
	EXPECT_EQ(answer, number_of_perfect_square_summands_needed(target));
}
