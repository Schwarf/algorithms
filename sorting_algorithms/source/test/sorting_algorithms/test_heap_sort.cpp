//
// Created by andreas on 12.02.22.
//
#include "./../../algorithms/heap_sort/heap_sort.h"
#include "gtest/gtest.h"
#include <algorithm>

class SetupHeapSort: public testing::Test
{
public:
	bool is_binary_heap(std::vector<int64_t> tree, size_t max_index)
	{
		while (max_index != 0) {
			auto child = tree[max_index];
			auto parent = tree[(max_index - 1) / 2];
			if( child > parent)
				return false;
			max_index--;
		}
		return true;
	}

protected:
	std::vector<int64_t> input{1, 2, 3, 4, 5, 10, 19, 89, 121, 1210, 7, 6};

};


TEST_F(SetupHeapSort, test_is_heap_sorted)
{
	auto heap_sort = HeapSort();
	auto heap_input = input;
	EXPECT_FALSE(is_binary_heap(input, input.size() - 1));
	std::make_heap(input.begin(), input.end());
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));
	EXPECT_FALSE(is_binary_heap(heap_input, input.size() - 1));
	heap_sort.sort(heap_input);
	EXPECT_TRUE(is_binary_heap(heap_input, input.size() - 1));
}