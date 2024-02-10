//
// Created by andreas on 30.01.24.
//
#include "gtest/gtest.h"
#include "./../interval_map.h"

TEST(TestIntervalMap, simple1)
{
	constexpr int start{1};
	constexpr int end{4};
	constexpr float value{1.f};
	auto map = IntervalMap<int, float>();
	map.add2(start, end, value);
	EXPECT_EQ(map[2], value);
	EXPECT_EQ(map[0], int{});
	EXPECT_EQ(map[1000], int{});
}


TEST(TestIntervalMap, simple2)
{
	const std::vector<int> start{1 , 3, 6 ,9 , 18};
	const std::vector<int> end{2 , 4, 7 ,15 , 21};
	const std::vector<double> value{1., 2., 3., 4., 5.};
	auto map = IntervalMap<int, double>();
	for(int i{}; i < start.size(); ++i)
		map.add2(start[i], end[i], value[i]);
	EXPECT_EQ(map[2], int{});
	EXPECT_EQ(map[10], value[3]);
	EXPECT_EQ(map[20], value[4]);
}


TEST(TestIntervalMap, internalOverlap1)
{
	const std::vector<int> starts{1, 6, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);
	EXPECT_EQ(map[2], values[0]);
	EXPECT_EQ(map[3], values[0]);
	EXPECT_EQ(map[4], values[0]);
	EXPECT_EQ(map[5], char{});
	EXPECT_EQ(map[6], values[1]);

	constexpr int start{3};
	constexpr int end{4};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[2], values[0]);
	EXPECT_EQ(map[3], value);
	EXPECT_EQ(map[4], values[0]);
	EXPECT_EQ(map[5], char{});
	EXPECT_EQ(map[6], values[1]);
}

TEST(TestIntervalMap, internalOverlap2)
{
	const std::vector<int> starts{1};
	const std::vector<int> ends{5};
	const std::vector<char> values{'a'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);
	EXPECT_EQ(map[-1], char{});
	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[3], values[0]);
	EXPECT_EQ(map[4], values[0]);
	EXPECT_EQ(map[5], char{});

}



TEST(TestIntervalMap, internalOverlapEndEqual)
{
	const std::vector<int> starts{1, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size() - 1; ++i)
		map.add2(starts[i], ends[i], values[i]);
	constexpr int start{3};
	constexpr int end{5};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[3], value);
	EXPECT_EQ(map[4], value);
	EXPECT_EQ(map[5], values[1]);
	EXPECT_EQ(map[6], values[1]);
}


TEST(TestIntervalMap, nooverlap)
{
	const std::vector<int> starts{1, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size() - 1; ++i)
		map.add2(starts[i], ends[i], values[i]);
	constexpr int start{3};
	constexpr int end{4};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[3], value);
	EXPECT_EQ(map[4], values[0]);
	EXPECT_EQ(map[5], values[1]);
	EXPECT_EQ(map[6], values[1]);
}


TEST(TestIntervalMap, overlap1)
{
	const std::vector<int> start{1, 3, 9};
	const std::vector<int> end{10, 7, 12};
	const std::vector<double> value{1., 2., 3.};
	auto map = IntervalMap<int, double>();
	for (int i{}; i < start.size() - 1; ++i)
		map.add2(start[i], end[i], value[i]);
	map.add2(start[2], end[2], value[2]);
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
		map.add2(start[i], end[i], value[i]);
	EXPECT_EQ(map[2], value[0]);
	EXPECT_EQ(map[4], value[4]);
	EXPECT_EQ(map[8], value[3]);
	EXPECT_EQ(map[9], value[3]);
}

TEST(TestIntervalMap, overwriteExistingIntervals1)
{
	const std::vector<int> starts{0, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);
	constexpr int start{0};
	constexpr int end{5};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[1], value);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);

}

TEST(TestIntervalMap, overwriteExistingIntervals2)
{
	const std::vector<int> starts{0, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);
	constexpr int start{5};
	constexpr int end{10};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], value);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);

}

TEST(TestIntervalMap, overwriteExistingIntervals3)
{
	const std::vector<int> starts{0, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);
	constexpr int start{0};
	constexpr int end{10};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[1], value);
	EXPECT_EQ(map[7], value);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);

}

TEST(TestIntervalMap, overwriteExistingIntervals4)
{
	const std::vector<int> starts{0, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);
	constexpr int start{0};
	constexpr int end{15};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[1], value);
	EXPECT_EQ(map[7], value);
	EXPECT_EQ(map[11], value);
	EXPECT_EQ(map[20], values[3]);

}

TEST(TestIntervalMap, overwriteExistingIntervals5)
{
	const std::vector<int> starts{0, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);
	constexpr int start{0};
	constexpr int end{1000};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[1], value);
	EXPECT_EQ(map[7], value);
	EXPECT_EQ(map[11], value);
	EXPECT_EQ(map[20], value);

}


TEST(TestIntervalMap, beginIsIn1)
{
	const std::vector<int> starts{0, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);
	constexpr int start{5};
	constexpr int end{8};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[5], value);
	EXPECT_EQ(map[7], value);
	EXPECT_EQ(map[8], values[1]);
	EXPECT_EQ(map[9], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);

}


TEST(TestIntervalMap, beginIsIn2)
{
	const std::vector<int> starts{0, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);
	constexpr int start{5};
	constexpr int end{12};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[5], value);
	EXPECT_EQ(map[7], value);
	EXPECT_EQ(map[8], value);
	EXPECT_EQ(map[9], value);
	EXPECT_EQ(map[11], value);
	EXPECT_EQ(map[12], values[2]);
	EXPECT_EQ(map[20], values[3]);

}

TEST(TestIntervalMap, beginIsIn3)
{
	const std::vector<int> starts{0, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);
	constexpr int start{0};
	constexpr int end{14};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[0], value);
	EXPECT_EQ(map[1], value);
	EXPECT_EQ(map[5], value);
	EXPECT_EQ(map[7], value);
	EXPECT_EQ(map[8], value);
	EXPECT_EQ(map[9], value);
	EXPECT_EQ(map[11], value);
	EXPECT_EQ(map[12], value);
	EXPECT_EQ(map[20], values[3]);

}


TEST(TestIntervalMap, endIsIn1)
{
	const std::vector<int> starts{0, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);
	constexpr int start{2};
	constexpr int end{5};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[0], values[0]);
	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[2], value);
	EXPECT_EQ(map[3], value);
	EXPECT_EQ(map[5], values[1]);
	EXPECT_EQ(map[9], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[12], values[2]);
	EXPECT_EQ(map[20], values[3]);

}


TEST(TestIntervalMap, endIsIn2)
{
	const std::vector<int> starts{0, 5, 10, 15};
	const std::vector<int> ends{5, 10, 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	EXPECT_EQ(map[20], values[3]);
	constexpr int start{2};
	constexpr int end{15};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[0], values[0]);
	EXPECT_EQ(map[1], values[0]);
	EXPECT_EQ(map[2], value);
	EXPECT_EQ(map[3], value);
	EXPECT_EQ(map[5], value);
	EXPECT_EQ(map[9], value);
	EXPECT_EQ(map[11], value);
	EXPECT_EQ(map[12], value);
	EXPECT_EQ(map[20], values[3]);
}



TEST(TestIntervalMap, fallback)
{
	const std::vector<int> starts{0, 7};
	const std::vector<int> ends{5, 10};
	const std::vector<char> values{'a', 'b'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[6], char{});
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], char{});
}



TEST(TestIntervalMap, merging1)
{
	const std::vector<int> starts{0, 7, 11};
	const std::vector<int> ends{5, 10, 13};
	const std::vector<char> values{'a', 'b', 'c'};
	auto map = IntervalMap<int, char>();
	for (int i{}; i < starts.size(); ++i)
		map.add2(starts[i], ends[i], values[i]);

	EXPECT_EQ(map[6], char{});
	EXPECT_EQ(map[7], values[1]);
	EXPECT_EQ(map[11], values[2]);
	constexpr int start{7};
	constexpr int end{13};
	constexpr char value{'b'};
	map.add2(start, end, value);
	EXPECT_EQ(map[12], values[1]);
}

TEST(TestIntervalMap, floatsimple1)
{
	constexpr float start{1.f};
	constexpr float end{4.f};
	constexpr float value{1.f};
	auto map = IntervalMap<int, float>();
	map.add2(start, end, value);
	EXPECT_FLOAT_EQ(map[2], value);
	EXPECT_FLOAT_EQ(map[0], float{});
	EXPECT_FLOAT_EQ(map[1000], float{});
}


TEST(TestIntervalMap, floatNooverlap)
{
	const std::vector<double> starts{1.0, 5.0000000000000002, 10, 15};
	const std::vector<double> ends{5.0, 10., 15, 1000};
	const std::vector<char> values{'a', 'b', 'c', 'd'};
	auto map = IntervalMap<double, char>();
	for (int i{}; i < starts.size() - 1; ++i)
		map.add2(starts[i], ends[i], values[i]);
	constexpr int start{3};
	constexpr int end{4};
	constexpr char value{'x'};
	map.add2(start, end, value);
	EXPECT_EQ(map[3], value);
	EXPECT_EQ(map[4], values[0]);
	EXPECT_EQ(map[5], values[1]);
	EXPECT_EQ(map[6], values[1]);
}
