//
// Created by andreas on 12.02.22.
//

#include "gtest/gtest.h"
#include "./../../heaps/binary_heap.h"
#include <algorithm>
#include <vector>

class SetupBinaryHeap: public testing::Test
{
public:
	template<typename T>
	bool is_binary_heap(T *tree, size_t highest_index)
	{
		while (highest_index != 0) {
			auto child = tree[highest_index];
			auto parent = tree[(highest_index - 1) / 2];
			if (child > parent)
				return false;
			highest_index--;
		}
		return true;
	}
	template<typename T>
	bool is_heap_GfG(T arr[], size_t i, size_t n)
	{
		if (i >= (n - 2) / 2)
			return true;

		if (arr[i] >= arr[2 * i + 1] &&
			arr[i] >= arr[2 * i + 2]
			&& is_heap_GfG(arr, 2 * i + 1, n)
			&& is_heap_GfG(arr, 2 * i + 2, n))
			return true;

		return false;
	}
	bool is_binary_heap(std::vector<int64_t> tree, size_t highest_index)
	{
		while (highest_index != 0) {
			auto child = tree[highest_index];
			auto parent = tree[(highest_index - 1) / 2];
			if (child > parent)
				return false;
			highest_index--;
		}
		return true;
	}

protected:
	std::vector<int64_t> input{1, 2, 3, 4, 5, 10, 19, 89, 121, 1210, 7, 6};

};


TEST_F(SetupBinaryHeap, test_binary_heap)
{
	auto heap = BinaryHeap<int64_t, 12>();
	for (const auto &element: input) {
		heap.insert(element);
	}
	std::make_heap(input.begin(), input.end());
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));
	EXPECT_TRUE(is_binary_heap(heap.get_array(), input.size() - 1));
	EXPECT_TRUE(is_heap_GfG(heap.get_array(), 0, input.size() - 1));
}


TEST_F(SetupBinaryHeap, test_binary_heap_pop_maximum)
{
	auto heap = BinaryHeap<int64_t, 12>();
	for (const auto &element: input) {
		heap.insert(element);
	}
	std::make_heap(input.begin(), input.end());
	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), heap.pop_maximum());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));
	EXPECT_TRUE(is_binary_heap(heap.get_array(), input.size() - 1));
	EXPECT_TRUE(is_heap_GfG(heap.get_array(), 0, input.size() - 1));

	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), heap.pop_maximum());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));
	EXPECT_TRUE(is_binary_heap(heap.get_array(), input.size() - 1));
	EXPECT_TRUE(is_heap_GfG(heap.get_array(), 0, input.size() - 1));

	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), heap.pop_maximum());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));
	EXPECT_TRUE(is_binary_heap(heap.get_array(), input.size() - 1));
	EXPECT_TRUE(is_heap_GfG(heap.get_array(), 0, input.size() - 1));

}


TEST_F(SetupBinaryHeap, test_binary_heap_pop_maximum_and_insert)
{
	auto heap = BinaryHeap<int64_t, 20>();
	for (const auto &element: input) {
		heap.insert(element);
	}

	heap.insert(-2);
	input.push_back(-2);
	std::make_heap(input.begin(), input.end());
	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), heap.pop_maximum());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));
	EXPECT_TRUE(is_binary_heap(heap.get_array(), input.size() - 1));
	EXPECT_TRUE(is_heap_GfG(heap.get_array(), 0, input.size() - 1));


	heap.insert(198);
	input.push_back(198);
	std::make_heap(input.begin(), input.end());
	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), heap.pop_maximum());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));
	EXPECT_TRUE(is_binary_heap(heap.get_array(), input.size() - 1));
	EXPECT_TRUE(is_heap_GfG(heap.get_array(), 0, input.size() - 1));

	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), heap.pop_maximum());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));
	EXPECT_TRUE(is_binary_heap(heap.get_array(), input.size() - 1));
	EXPECT_TRUE(is_heap_GfG(heap.get_array(), 0, input.size() - 1));

	heap.insert(198);
	input.push_back(198);
	std::make_heap(input.begin(), input.end());
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));
	EXPECT_TRUE(is_binary_heap(heap.get_array(), input.size() - 1));
	EXPECT_TRUE(is_heap_GfG(heap.get_array(), 0, input.size() - 1));

}
