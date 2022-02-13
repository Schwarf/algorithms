//
// Created by andreas on 12.02.22.
//

#include "gtest/gtest.h"
#include "./../../heaps/k_ary_heap.h"
#include <algorithm>
#include <vector>

class SetupK_aryHeap: public testing::Test
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

	template<typename T, size_t number_of_nodes>
	bool is_k_ary_heap(T *tree, size_t highest_index)
	{
		while (highest_index != 0) {
			auto child = tree[highest_index];
			auto parent = tree[(highest_index - 1) / number_of_nodes];
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

protected:
	std::vector<int64_t> input{1, 2, 3, 4, 5, 10, 19, 89, 121, 1210, 7, 6};

};


TEST_F(SetupK_aryHeap, test_binary_heap)
{
	constexpr size_t number_of_nodes = 2;
	auto heap = K_aryHeap<int64_t, number_of_nodes,  12>();
	for (const auto &element: input) {
		heap.insert(element);
	}
	EXPECT_TRUE(is_binary_heap(heap.get_array(), input.size() - 1));
	EXPECT_TRUE(is_heap_GfG(heap.get_array(), 0, input.size() - 1));
	auto result = is_k_ary_heap<int64_t, number_of_nodes>(heap.get_array(), input.size() - 1);
	EXPECT_TRUE(result);
}

TEST_F(SetupK_aryHeap, test_tenary_heap)
{
	constexpr size_t number_of_nodes = 3;
	auto heap = K_aryHeap<int64_t, number_of_nodes,  12>();
	for (const auto &element: input) {
		heap.insert(element);
	}
	auto result = is_k_ary_heap<int64_t, number_of_nodes>(heap.get_array(), input.size() - 1);
	EXPECT_TRUE(result);
	auto result_binary_heap = is_k_ary_heap<int64_t, number_of_nodes - 1>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_binary_heap);
}

TEST_F(SetupK_aryHeap, test_quaternary_heap)
{
	constexpr size_t number_of_nodes = 4;
	auto heap = K_aryHeap<int64_t, number_of_nodes,  12>();
	for (const auto &element: input) {
		heap.insert(element);
	}
	auto result = is_k_ary_heap<int64_t, number_of_nodes>(heap.get_array(), input.size() - 1);
	EXPECT_TRUE(result);
	auto result_binary_heap = is_k_ary_heap<int64_t, number_of_nodes - 2>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_binary_heap);
	auto result_tenary_heap = is_k_ary_heap<int64_t, number_of_nodes - 1>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_tenary_heap);

}


TEST_F(SetupK_aryHeap, test_quinary_heap)
{
	constexpr size_t number_of_nodes = 5;
	auto heap = K_aryHeap<int64_t, number_of_nodes,  12>();
	for (const auto &element: input) {
		heap.insert(element);
	}
	auto result = is_k_ary_heap<int64_t, number_of_nodes>(heap.get_array(), input.size() - 1);
	EXPECT_TRUE(result);
	auto result_binary_heap = is_k_ary_heap<int64_t, number_of_nodes - 3>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_binary_heap);
	auto result_tenary_heap = is_k_ary_heap<int64_t, number_of_nodes - 2>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_tenary_heap);
	auto result_quaternary_heap = is_k_ary_heap<int64_t, number_of_nodes - 1>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_quaternary_heap);
}


TEST_F(SetupK_aryHeap, test_senary_heap)
{
	constexpr size_t number_of_nodes = 6;
	auto heap = K_aryHeap<int64_t, number_of_nodes,  12>();
	for (const auto &element: input) {
		heap.insert(element);
	}
	auto result = is_k_ary_heap<int64_t, number_of_nodes>(heap.get_array(), input.size() - 1);
	EXPECT_TRUE(result);
	auto result_binary_heap = is_k_ary_heap<int64_t, number_of_nodes - 4>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_binary_heap);
	auto result_tenary_heap = is_k_ary_heap<int64_t, number_of_nodes - 3>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_tenary_heap);
	auto result_quaternary_heap = is_k_ary_heap<int64_t, number_of_nodes - 2>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_quaternary_heap);
	auto result_quinery_heap = is_k_ary_heap<int64_t, number_of_nodes - 1>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_quinery_heap);
}

TEST_F(SetupK_aryHeap, test_tenary_heap_pop_maximum)
{
	constexpr size_t number_of_nodes =3;
	auto heap = K_aryHeap<int64_t, number_of_nodes, 12>();
	for (const auto &element: input) {
		heap.insert(element);
	}
	auto result = is_k_ary_heap<int64_t, number_of_nodes>(heap.get_array(), input.size() - 1);
	EXPECT_TRUE(result);
	auto result_binary_heap = is_k_ary_heap<int64_t, number_of_nodes - 1>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_binary_heap);
	EXPECT_EQ(heap.pop_maximum(), *std::max_element(input.begin(), input.end()));

	result = is_k_ary_heap<int64_t, number_of_nodes>(heap.get_array(), input.size() - 1);
	EXPECT_TRUE(result);
	result_binary_heap = is_k_ary_heap<int64_t, number_of_nodes - 1>(heap.get_array(), input.size() - 1);
	EXPECT_FALSE(result_binary_heap);

}

