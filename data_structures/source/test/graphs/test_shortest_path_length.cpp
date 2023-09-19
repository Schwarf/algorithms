//
// Created by andreas on 19.09.23.
//
#include "gtest/gtest.h"
#include "graphs/shortest_path_length.h"

TEST(TestShortestPathLength, simple1)
{
	std::vector<std::vector<unsigned short>> graph{{1, 2, 3}, {0}, {0}, {0}};
	constexpr unsigned short expected_output{4};
	EXPECT_EQ(expected_output, shortest_path_length(graph));
}

TEST(TestShortestPathLength, simple2)
{
	std::vector<std::vector<unsigned long>> graph{{1L}, {0L, 2L, 4L}, {1L, 3L, 4L}, {2L}, {1L, 2L}};
	constexpr unsigned long expected_output{4L};
	EXPECT_EQ(expected_output, shortest_path_length(graph));
}