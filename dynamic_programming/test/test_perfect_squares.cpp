//
// Created by andreas on 22.11.22.
//
#include "gtest/gtest.h"
#include "perfect_square.h"

class SetupPerfectSquares: public testing::Test
{
protected:
	int target1{1};
	int answer1{1};
	int target2{12};
	int answer2{3};
	int target3{13};
	int answer3{2};
	int target4{1791};
	int answer4{4};
	int target5{9973};
	int answer5{2};

};


TEST_F(SetupPerfectSquares, SetupPerfectSquare_12)
{
	EXPECT_EQ(answer2, number_of_perfect_square_summands_needed(target2));
}


TEST_F(SetupPerfectSquares, SetupPerfectSquare_13)
{
	EXPECT_EQ(answer3, number_of_perfect_square_summands_needed(target3));
}

TEST_F(SetupPerfectSquares, SetupPerfectSquare_1791)
{
	EXPECT_EQ(answer4, number_of_perfect_square_summands_needed(target4));
}

TEST_F(SetupPerfectSquares, SetupPerfectSquare_9973)
{
	EXPECT_EQ(answer5, number_of_perfect_square_summands_needed(target5));
}

TEST_F(SetupPerfectSquares, SetupPerfectSquare_1)
{
	EXPECT_EQ(answer1, number_of_perfect_square_summands_needed(target1));
}
