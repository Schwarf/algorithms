//
// Created by andreas on 12.02.22.
//

#include "gtest/gtest.h"
#include "heaps/binary_heap.h"
#include <vector>
#include <random>
#include <queue>

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
	static inline int get_random(const int &lower_bound, const int &upper_bound)
	{
		auto int_distribution_ = std::uniform_int_distribution<int>(lower_bound, upper_bound);
		std::random_device device;
		auto generator = std::mt19937(device());
		return int_distribution_(generator);
	}


protected:
	std::vector<int64_t> input{1, 2, 3, 4, 5, 10, 19, 89, 121, 1210, 7, 6};

};


TEST_F(SetupBinaryHeap, test_binary_heap)
{
	auto max_heap = StackHeap<int64_t, 12>();
	std::priority_queue<int64_t> q;
	for (const auto &element: input) {
		EXPECT_TRUE(max_heap.insert(element));
		q.push(element);
		EXPECT_EQ(q.top(), max_heap.top());
	}
	std::make_heap(input.begin(), input.end());
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));
}

TEST_F(SetupBinaryHeap, test_binary_heap_many_random_numbers_top)
{
	constexpr int limit = 10000;
	auto max_heap = StackHeap<int64_t, limit>();
	int count{};
	std::priority_queue<int64_t> expected_result;
	while (count < limit) {
		auto element = input[count++];
		max_heap.insert(element);
		expected_result.push(element);
		EXPECT_EQ(max_heap.top(), expected_result.top());
	}
}

TEST_F(SetupBinaryHeap, test_binary_heap_many_random_numbers_pop)
{
	constexpr int limit = 10000;
	auto max_heap = StackHeap<int64_t, limit>();
	int count{};
	std::priority_queue<int64_t> expected_result;
	while (count++ < limit) {
		auto element = get_random(-10000000, 2000000);
		max_heap.insert(element);
		expected_result.push(element);
	}
	for (int i{}; i < limit; ++i) {
		EXPECT_EQ(max_heap.top(), expected_result.top());
		expected_result.pop();
		max_heap.pop();
	}
}


TEST_F(SetupBinaryHeap, test_binary_heap_pop)
{
	auto max_heap = StackHeap<int64_t, 12>();
	for (const auto &element: input) {
		max_heap.insert(element);
	}
	std::make_heap(input.begin(), input.end());
	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), max_heap.pop());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));

	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), max_heap.pop());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));

	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), max_heap.pop());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));

}


TEST_F(SetupBinaryHeap, test_binary_heap_pop_and_insert)
{
	auto max_heap = StackHeap<int64_t, 20>();
	for (const auto &element: input) {
		max_heap.insert(element);
	}

	max_heap.insert(-2);
	input.push_back(-2);
	std::make_heap(input.begin(), input.end());
	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), max_heap.pop());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));


	max_heap.insert(198);
	input.push_back(198);
	std::make_heap(input.begin(), input.end());
	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), max_heap.pop());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));

	std::pop_heap(input.begin(), input.end());
	EXPECT_EQ(input.back(), max_heap.pop());
	input.pop_back();
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));

	max_heap.insert(198);
	input.push_back(198);
	std::make_heap(input.begin(), input.end());
	EXPECT_TRUE(is_binary_heap(input, input.size() - 1));

}
