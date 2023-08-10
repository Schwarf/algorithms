//
// Created by andreas on 10.08.23.
//
#include "gtest/gtest.h"
#include "./../find_element_index_in_rotated_array.h"

TEST(FindElementIndexInRotatedArray, simple1)
{
	const std::vector<float> input{4.f, 5.f, 6.f, 7.f, 0.f, 1.f, 2.f};
	constexpr float target{};
	constexpr int expected_index{4};
	EXPECT_EQ(expected_index, find_element_index_in_rotated_array(input, target));
}

TEST(FindElementIndexInRotatedArray, simple2)
{
	const std::vector<float> input{4.f, 5.f, 6.f, 7.f, 0.f, 1.f, 2.f};
	constexpr float target{3.f};
	constexpr int expected_index{-1};
	EXPECT_EQ(expected_index, find_element_index_in_rotated_array(input, target));
}

TEST(FindElementIndexInRotatedArray, simple3)
{
	const std::vector<int> input{1};
	constexpr int target{0};
	constexpr int expected_index{-1};
	EXPECT_EQ(expected_index, find_element_index_in_rotated_array(input, target));
}


TEST(FindElementIndexInRotatedArray, complex1)
{
	const std::vector<int> input
		{284, 287, 289, 293, 295, 298, 0, 3, 8, 9, 10, 11, 12, 15, 17, 19, 20, 22, 26, 29, 30, 31, 35, 36, 37, 38, 42,
		 43, 45, 50, 51, 54, 56, 58, 59, 60, 62, 63, 68, 70, 73, 74, 81, 83, 84, 87, 92, 95, 99, 101, 102, 105, 108,
		 109, 112, 114, 115, 116, 122, 125, 126, 127, 129, 132, 134, 136, 137, 138, 139, 147, 149, 152, 153, 154, 155,
		 159, 160, 161, 163, 164, 165, 166, 168, 169, 171, 172, 174, 176, 177, 180, 187, 188, 190, 191, 192, 198, 200,
		 203, 204, 206, 207, 209, 210, 212, 214, 216, 221, 224, 227, 228, 229, 230, 233, 235, 237, 241, 242, 243, 244,
		 246, 248, 252, 253, 255, 257, 259, 260, 261, 262, 265, 266, 268, 269, 270, 271, 272, 273, 277, 279, 281};
	constexpr int target{235};
	constexpr int expected_index{113};
	EXPECT_EQ(expected_index, find_element_index_in_rotated_array(input, target));
}

TEST(FindElementIndexInRotatedArray, complex2)
{
	const std::vector<int> input
		{284, 287, 289, 293, 295, 298, 0, 3, 8, 9, 10, 11, 12, 15, 17, 19, 20, 22, 26, 29, 30, 31, 35, 36, 37, 38, 42,
		 43, 45, 50, 51, 54, 56, 58, 59, 60, 62, 63, 68, 70, 73, 74, 81, 83, 84, 87, 92, 95, 99, 101, 102, 105, 108,
		 109, 112, 114, 115, 116, 122, 125, 126, 127, 129, 132, 134, 136, 137, 138, 139, 147, 149, 152, 153, 154, 155,
		 159, 160, 161, 163, 164, 165, 166, 168, 169, 171, 172, 174, 176, 177, 180, 187, 188, 190, 191, 192, 198, 200,
		 203, 204, 206, 207, 209, 210, 212, 214, 216, 221, 224, 227, 228, 229, 230, 233, 235, 237, 241, 242, 243, 244,
		 246, 248, 252, 253, 255, 257, 259, 260, 261, 262, 265, 266, 268, 269, 270, 271, 272, 273, 277, 279, 281};
	constexpr int target{2};
	constexpr int expected_index{-1};
	EXPECT_EQ(expected_index, find_element_index_in_rotated_array(input, target));
}

TEST(FindElementIndexInRotatedArrayOptimized, simple1)
{
	const std::vector<float> input{4.f, 5.f, 6.f, 7.f, 0.f, 1.f, 2.f};
	constexpr float target{};
	constexpr int expected_index{4};
	EXPECT_EQ(expected_index, find_element_index_in_rotated_array_optimized(input, target));
}

TEST(FindElementIndexInRotatedArrayOptimized, simple2)
{
	const std::vector<float> input{4.f, 5.f, 6.f, 7.f, 0.f, 1.f, 2.f};
	constexpr float target{3.f};
	constexpr int expected_index{-1};
	EXPECT_EQ(expected_index, find_element_index_in_rotated_array_optimized(input, target));
}

TEST(FindElementIndexInRotatedArrayOptimized, simple3)
{
	const std::vector<int> input{1};
	constexpr int target{0};
	constexpr int expected_index{-1};
	EXPECT_EQ(expected_index, find_element_index_in_rotated_array_optimized(input, target));
}


TEST(FindElementIndexInRotatedArrayOptimized, complex1)
{
	const std::vector<int> input
		{284, 287, 289, 293, 295, 298, 0, 3, 8, 9, 10, 11, 12, 15, 17, 19, 20, 22, 26, 29, 30, 31, 35, 36, 37, 38, 42,
		 43, 45, 50, 51, 54, 56, 58, 59, 60, 62, 63, 68, 70, 73, 74, 81, 83, 84, 87, 92, 95, 99, 101, 102, 105, 108,
		 109, 112, 114, 115, 116, 122, 125, 126, 127, 129, 132, 134, 136, 137, 138, 139, 147, 149, 152, 153, 154, 155,
		 159, 160, 161, 163, 164, 165, 166, 168, 169, 171, 172, 174, 176, 177, 180, 187, 188, 190, 191, 192, 198, 200,
		 203, 204, 206, 207, 209, 210, 212, 214, 216, 221, 224, 227, 228, 229, 230, 233, 235, 237, 241, 242, 243, 244,
		 246, 248, 252, 253, 255, 257, 259, 260, 261, 262, 265, 266, 268, 269, 270, 271, 272, 273, 277, 279, 281};
	constexpr int target{235};
	constexpr int expected_index{113};
	EXPECT_EQ(expected_index, find_element_index_in_rotated_array_optimized(input, target));
}

TEST(FindElementIndexInRotatedArrayOptimized, complex2)
{
	const std::vector<int> input
		{284, 287, 289, 293, 295, 298, 0, 3, 8, 9, 10, 11, 12, 15, 17, 19, 20, 22, 26, 29, 30, 31, 35, 36, 37, 38, 42,
		 43, 45, 50, 51, 54, 56, 58, 59, 60, 62, 63, 68, 70, 73, 74, 81, 83, 84, 87, 92, 95, 99, 101, 102, 105, 108,
		 109, 112, 114, 115, 116, 122, 125, 126, 127, 129, 132, 134, 136, 137, 138, 139, 147, 149, 152, 153, 154, 155,
		 159, 160, 161, 163, 164, 165, 166, 168, 169, 171, 172, 174, 176, 177, 180, 187, 188, 190, 191, 192, 198, 200,
		 203, 204, 206, 207, 209, 210, 212, 214, 216, 221, 224, 227, 228, 229, 230, 233, 235, 237, 241, 242, 243, 244,
		 246, 248, 252, 253, 255, 257, 259, 260, 261, 262, 265, 266, 268, 269, 270, 271, 272, 273, 277, 279, 281};
	constexpr int target{2};
	constexpr int expected_index{-1};
	EXPECT_EQ(expected_index, find_element_index_in_rotated_array_optimized(input, target));
}
