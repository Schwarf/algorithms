//
// Created by andreas on 04.11.23.
//
#include "gtest/gtest.h"
#include "sort_according_to_hamming_weight.h"


TEST(SortAccordingToHammingWeight, simple_inefficient1)
{
	std::vector<int> input{0, 1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> expected_result{0, 1, 2, 4, 8, 3, 5, 6, 7};
	sort_according_to_hamming_weight(input, get_hamming_weight_inefficient<int>);
	EXPECT_EQ(input, expected_result);
}

TEST(SortAccordingToHammingWeight, simple1)
{
	std::vector<int> input{0, 1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> expected_result{0, 1, 2, 4, 8, 3, 5, 6, 7};
	sort_according_to_hamming_weight(input, get_hamming_weight<int>);
	EXPECT_EQ(input, expected_result);
}


TEST(SortAccordingToHammingWeight, simple_inefficient2)
{
	std::vector<int> input{1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
	std::vector<int> expected_result{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
	sort_according_to_hamming_weight(input, get_hamming_weight_inefficient<int>);
	EXPECT_EQ(input, expected_result);
}

TEST(SortAccordingToHammingWeight, simple2)
{
	std::vector<int> input{1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
	std::vector<int> expected_result{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
	sort_according_to_hamming_weight(input, get_hamming_weight<int>);
	EXPECT_EQ(input, expected_result);
}


TEST(SortAccordingToHammingWeight, inefficient1)
{
	std::vector<int> input
		{9778, 9013, 5133, 472, 7373, 4494, 1504, 145, 2780, 5385, 4256, 5203, 1210, 2749, 446, 4983, 1698, 626, 2562, 1968, 7792, 4357, 8756, 8805, 4051, 5505, 3850, 8592, 6683, 382, 1574, 9433, 5849, 1569, 1369, 3385, 353};
	std::vector<int> expected_result
		{145, 2562, 4256, 353, 1569, 4357, 8592, 472, 626, 1504, 1574, 1698, 5133, 5385, 5505, 8756, 1210, 1369, 1968, 3850, 4494, 5203, 8805, 9778, 382, 446, 2780, 3385, 6683, 7792, 9013, 9433, 2749, 5849, 7373, 4051, 4983};
	sort_according_to_hamming_weight(input, get_hamming_weight_inefficient<int>);
	EXPECT_EQ(input, expected_result);
}

TEST(SortAccordingToHammingWeight, 1)
{
	std::vector<int> input
		{9778, 9013, 5133, 472, 7373, 4494, 1504, 145, 2780, 5385, 4256, 5203, 1210, 2749, 446, 4983, 1698, 626, 2562, 1968, 7792, 4357, 8756, 8805, 4051, 5505, 3850, 8592, 6683, 382, 1574, 9433, 5849, 1569, 1369, 3385, 353};
	std::vector<int> expected_result
		{145, 2562, 4256, 353, 1569, 4357, 8592, 472, 626, 1504, 1574, 1698, 5133, 5385, 5505, 8756, 1210, 1369, 1968, 3850, 4494, 5203, 8805, 9778, 382, 446, 2780, 3385, 6683, 7792, 9013, 9433, 2749, 5849, 7373, 4051, 4983};
	sort_according_to_hamming_weight(input, get_hamming_weight<int>);
	EXPECT_EQ(input, expected_result);
}
