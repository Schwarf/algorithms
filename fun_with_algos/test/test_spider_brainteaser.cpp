//
// Created by andreas on 06.11.23.
//
#include "gtest/gtest.h"
#include "spider_brainteaser.h"

TEST(SpiderBrainteaser, simple1)
{
	const std::vector<unsigned int> left{4,3};
	const std::vector<unsigned int> right{0,1};
	constexpr unsigned int n{4};
	constexpr unsigned int expected_result{4};
	EXPECT_EQ(get_last_moment(n, left, right), expected_result);
}

TEST(SpiderBrainteaser, simple2)
{
	const std::vector<unsigned int> left{0,1,2,3};
	const std::vector<unsigned int> right{};
	constexpr unsigned int n{3};
	constexpr unsigned int expected_result{3};
	EXPECT_EQ(get_last_moment(n, left, right), expected_result);
}

TEST(SpiderBrainteaser, simple3)
{
	const std::vector<unsigned int> left{};
	const std::vector<unsigned int> right{0,1,2,3};
	constexpr unsigned int n{3};
	constexpr unsigned int expected_result{3};
	EXPECT_EQ(get_last_moment(n, left, right), expected_result);
}

TEST(SpiderBrainteaser, simple4)
{
	const std::vector<unsigned int> left{4,7,15};
	const std::vector<unsigned int> right{9,3,13,10};
	constexpr unsigned int n{20};
	constexpr unsigned int expected_result{17};
	EXPECT_EQ(get_last_moment(n, left, right), expected_result);
}

TEST(SpiderBrainteaser, complex1)
{
	const std::vector<unsigned int> left{};
	const std::vector<unsigned int> right{76,18,36,52,29,58,6,68,61,63,57,79,70,86,98,83,21,0,14,90,101,64,78,16,60,89,71,67,65,92,96,55,12,10,30,104,45,51,9,1,72,38,94,73,87,24,37,19,80,42,28,88,7,44,74,75,8,62,77,4,48,82,13,47,40};
	constexpr unsigned int n{105};
	constexpr unsigned int expected_result{105};
	EXPECT_EQ(get_last_moment(n, left, right), expected_result);
}
