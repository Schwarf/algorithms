//
// Created by andreas on 13.01.24.
//
#include "gtest/gtest.h"
#include "./../levenshtein_distance.h"

TEST(TestLevenshteinDistanceTest, simple1)
{
	const std::string input1{"abc"};
	const std::string input2{"bbd"};
	constexpr int expected_result{2};
	EXPECT_EQ(levenshtein_distance(input1, input2), expected_result);
}

TEST(TestLevenshteinDistanceTest, simple2)
{
	const std::string input1{"abc"};
	const std::string input2{};
	constexpr int expected_result{3};
	EXPECT_EQ(levenshtein_distance(input1, input2), expected_result);
}

TEST(TestLevenshteinDistanceTest, simple3)
{
	const std::string input1{};
	const std::string input2{"hdakdakl"};
	constexpr int expected_result{8};
	EXPECT_EQ(levenshtein_distance(input1, input2), expected_result);
}


TEST(TestLevenshteinDistanceTest, simple4)
{
	const std::string input1{"fjisaojfsaioffjfjmnfiw3ruioufioer8409480923"};
	const std::string input2{"309rucmsapicmoxzvmjh509y09gjdiovnsdmgc,o-c9-0rj"};
	constexpr int expected_result{41};
	EXPECT_EQ(levenshtein_distance(input1, input2), expected_result);
}

TEST(TestLevenshteinDistanceTest, simple5)
{
	const std::string input1{"abaghahaha"};
	const std::string input2{"abaghbgbgb"};
	constexpr int expected_result{5};
	EXPECT_EQ(levenshtein_distance(input1, input2), expected_result);
}

TEST(TestLevenshteinDistanceTest, simple6)
{
	const std::string input1{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
	const std::string input2{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	constexpr int expected_result{52};
	EXPECT_EQ(levenshtein_distance(input1, input2), expected_result);
}
