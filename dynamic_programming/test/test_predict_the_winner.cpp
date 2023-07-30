//
// Created by andreas on 28.07.23.
//
#include "gtest/gtest.h"

#include "predict_the_winner.h"

TEST(PredictTheWinner, simple1)
{
	std::vector<int> input{1, 5, 2};
	EXPECT_FALSE(predict_the_winner_recursion(input));
}

TEST(PredictTheWinner, simple2)
{
	std::vector<int> input{1, 5, 233, 7};
	EXPECT_TRUE(predict_the_winner_recursion(input));
}

TEST(PredictTheWinner, simple3)
{
	std::vector<int> input{0, 0, 7, 6, 5, 6, 1};
	EXPECT_FALSE(predict_the_winner_recursion(input));
}

TEST(PredictTheWinner, simple4)
{
	std::vector<double> input{1.12718};
	EXPECT_TRUE(predict_the_winner_recursion(input));
}

TEST(PredictTheWinner, simple5)
{
	std::vector<short> input{10, 10, 2, 2, 454, 2, 2, 3};
	EXPECT_TRUE(predict_the_winner_recursion(input));
}


TEST(PredictTheWinner_TopDown, simple1)
{
	std::vector<int> input{1, 5, 2};
	EXPECT_FALSE(predict_the_winner_top_down(input));
}

TEST(PredictTheWinner_TopDown, simple2)
{
	std::vector<int> input{1, 5, 233, 7};
	EXPECT_TRUE(predict_the_winner_top_down(input));
}

TEST(PredictTheWinner_TopDown, simple3)
{
	std::vector<int> input{0, 0, 7, 6, 5, 6, 1};
	EXPECT_FALSE(predict_the_winner_top_down(input));
}

TEST(PredictTheWinner_TopDown, simple4)
{
	std::vector<double> input{1.12718};
	EXPECT_TRUE(predict_the_winner_top_down(input));
}

TEST(PredictTheWinner_TopDown, simple5)
{
	std::vector<short> input{10, 10, 2, 2, 454, 2, 2, 3};
	EXPECT_TRUE(predict_the_winner_top_down(input));
}

TEST(PredictTheWinner_bottom_up, simple1)
{
	std::vector<int> input{1, 5, 2};
	EXPECT_FALSE(predict_the_winner_bottom_up(input));
}

TEST(PredictTheWinner_bottom_up, simple2)
{
	std::vector<int> input{1, 5, 233, 7};
	EXPECT_TRUE(predict_the_winner_bottom_up(input));
}

TEST(PredictTheWinner_bottom_up, simple3)
{
	std::vector<int> input{0, 0, 7, 6, 5, 6, 1};
	EXPECT_FALSE(predict_the_winner_bottom_up(input));
}

TEST(PredictTheWinner_bottom_up, simple4)
{
	std::vector<double> input{1.12718};
	EXPECT_TRUE(predict_the_winner_bottom_up(input));
}

TEST(PredictTheWinner_bottom_up, simple5)
{
	std::vector<short> input{10, 10, 2, 2, 454, 2, 2, 3};
	EXPECT_TRUE(predict_the_winner_bottom_up(input));
}


TEST(PredictTheWinner_optimized, simple1)
{
	std::vector<int> input{1, 5, 2};
	EXPECT_FALSE(predict_the_winner_optimized(input));
}

TEST(PredictTheWinner_optimized, simple2)
{
	std::vector<int> input{1, 5, 233, 7};
	EXPECT_TRUE(predict_the_winner_optimized(input));
}

TEST(PredictTheWinner_optimized, simple3)
{
	std::vector<int> input{0, 0, 7, 6, 5, 6, 1};
	EXPECT_FALSE(predict_the_winner_optimized(input));
}

TEST(PredictTheWinner_optimized, simple4)
{
	std::vector<double> input{1.12718};
	EXPECT_TRUE(predict_the_winner_optimized(input));
}

TEST(PredictTheWinner_optimized, simple5)
{
	std::vector<short> input{10, 10, 2, 2, 454, 2, 2, 3};
	EXPECT_TRUE(predict_the_winner_optimized(input));
}
