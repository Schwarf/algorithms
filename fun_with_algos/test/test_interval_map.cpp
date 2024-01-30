//
// Created by andreas on 30.01.24.
//
#include "gtest/gtest.h"
#include "./../interval_map.h"

//TEST(TestIntervalMap, simple1)
//{
//	constexpr int start{1};
//	constexpr int end{4};
//	constexpr float value{1.f};
//	auto map = IntervalMap<int, float>();
//	map.add(start, end, value);
//	EXPECT_EQ(map[2], value);
//	EXPECT_EQ(map[0], value);
//	EXPECT_EQ(map[1000], value);
//}
//
//
//TEST(TestIntervalMap, simple2)
//{
//	const std::vector<int> start{1 , 3, 6 ,9 , 18};
//	const std::vector<int> end{2 , 4, 7 ,15 , 21};
//	const std::vector<double> value{1., 2., 3., 4., 5.};
//	auto map = IntervalMap<int, double>();
//	for(int i{}; i < start.size(); ++i)
//		map.add(start[i], end[i], value[i]);
//	EXPECT_EQ(map[2], value[0]);
//	EXPECT_EQ(map[10], value[3]);
//	EXPECT_EQ(map[20], value[4]);
//}

TEST(TestIntervalMap, overlap1)
{
	const std::vector<int> start{1, 3, 9};
	const std::vector<int> end{10, 7, 12};
	const std::vector<double> value{1., 2., 3.};
	auto map = IntervalMap<int, double>();
	for (int i{}; i < start.size() - 1; ++i)
		map.add(start[i], end[i], value[i]);
	map.add(start[2], end[2], value[2]);
	EXPECT_EQ(map[2], value[0]);
	EXPECT_EQ(map[6], value[1]);
	EXPECT_EQ(map[11], value[2]);
	EXPECT_EQ(map[8], value[0]);
}


TEST(TestIntervalMap, overlap2)
{
	const std::vector<int> start{1, 3, 5, 7, 3};
	const std::vector<int> end{3, 5, 7, 10, 8};
	const std::vector<double> value{1., 2., 3., 4., 10.};
	auto map = IntervalMap<int, double>();
	for (int i{}; i < start.size(); ++i)
		map.add(start[i], end[i], value[i]);
	EXPECT_EQ(map[2], value[0]);
	EXPECT_EQ(map[4], value[4]);
	EXPECT_EQ(map[8], value[0]);
	EXPECT_EQ(map[9], value[3]);
}
