//
// Created by andreas on 29.03.24.
//

#include "gtest/gtest.h"
#include "./../count_subarrays_where_max_appears_k_times.h"

TEST(TestCountSubarraysWithMaxKTimes, simple1)
{
	const std::vector<float> input{1.f, 3.f, 2.f, 3.f, 3.f};
	constexpr int required_frequency{1};
	constexpr long long expected_result{13};
	EXPECT_EQ(expected_result, count_subarrays_where_max_appears_k_times(input, required_frequency));
}

TEST(TestCountSubarraysWithMaxKTimes, simple2)
{
	const std::vector<float> input{1.f, 3.f, 2.f, 3.f, 3.f};
	constexpr int required_frequency{1};
	constexpr long long expected_result{13};
	EXPECT_EQ(expected_result, count_subarrays_where_max_appears_k_times(input, required_frequency));
}

TEST(TestCountSubarraysWithMaxKTimes, simple3)
{
	const std::vector<float> input{1.f, 3.f, 2.f, 3.f, 3.f};
	constexpr int required_frequency{4};
	constexpr long long expected_result{0};
	EXPECT_EQ(expected_result, count_subarrays_where_max_appears_k_times(input, required_frequency));
}

TEST(TestCountSubarraysWithMaxKTimes, medium1)
{
	const std::vector<int> input
		{306, 537, 692, 692, 414, 598, 253, 372, 675, 489, 646, 618, 674, 692, 585, 43, 467, 169, 506, 692, 228, 541,
		 609, 553, 205, 141, 503, 556, 642, 642, 262, 692, 347, 523, 64, 157, 692, 692, 635, 462, 323, 402, 376, 692,
		 53, 162, 692, 692, 190, 692, 587, 636, 298, 691, 262, 271, 482, 692, 270, 135, 136, 664, 692, 299, 692, 407,
		 279, 692, 692, 692, 692, 692, 692, 692, 363, 176, 530, 294, 129, 692, 543, 692, 692, 508, 546, 692, 489, 530,
		 692, 692, 148, 692, 538, 109, 224, 277, 77, 692, 692, 87, 525, 175, 53, 112, 102, 304, 448, 498, 359, 692, 428,
		 692, 127, 692, 692, 605, 492, 212, 72, 692, 692, 381, 692, 692, 522, 692, 645, 692, 556, 441, 435, 516, 456,
		 158, 532, 7, 506, 91, 362, 692, 653, 251, 403, 167, 328, 128, 449, 67, 413, 242, 655, 380, 233, 647, 164, 317,
		 382, 429, 401, 601, 534, 681, 413, 415, 692, 692, 692, 515, 415};
	constexpr int required_frequency{10};
	constexpr long long expected_result{9290};
	EXPECT_EQ(expected_result, count_subarrays_where_max_appears_k_times(input, required_frequency));
}