//
// Created by andreas on 03.06.22.
//

#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H
#include <vector>
// Given an integer array nums, handle multiple queries of the following types:
//
// Update the value of an element in nums.
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
//
// Implement the SegmentTree class:
//
// SegmentTree(const std::vector<int> &nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to be val.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

// A Segment Tree, also known as a statistic tree,
// is a tree data structure used for storing information about intervals, or segments.
// It allows querying which of the stored segments contain a given point.
// It is, in principle, a static structure; that is, it’s a structure that cannot be modified once it’s built.

template<typename T>
class SegmentTree
{
public:
	// The segment tree stores the original array as the leaves of a binary tree in the second half
	// of the internal array representation. Starting from these leaf nodes, the parent nodes are
	// constructed bottom-up, where each parent stores the sum (or min, max, etc.) of its two children.
	// The root node is stored at index 1, while index 0 is unused.
	// For a node at index i, its left child is at 2*i and its right child is at 2*i + 1.
	// Equivalently, from the parent's point of view, left children have even indices and right
	// children have odd indices.
	explicit SegmentTree(const std::vector<T> &input)
	{
		if (input.empty())
			return;
		tree_size_ = 2 * input.size();
		tree_ = std::vector<T>(tree_size_);
		build_tree(input);
	}

	void update(int index, T val)
	{
		// input is stored in second half of tree
		index += tree_size_ / 2;
		// update leaf
		tree_[index] = val;
		// update parents
		while (index > 1) {
			int left = index;
			int right = index;

			if (index & 1)
				left--;
			else
				right++;
			tree_[index / 2] = tree_[left] + tree_[right];
			index /= 2;
		}
	}

	T sum_range(int left_index, int right_index)
	{
		left_index += tree_size_ / 2;
		right_index += tree_size_ / 2;
		T sum{};
		while (left_index <= right_index) {
			if (left_index & 1)
				sum += tree_[left_index++];
			if (!(right_index & 1))
				sum += tree_[right_index--];
			left_index /= 2;
			right_index /= 2;
		}
		return sum;
	}


private:
	void build_tree(const std::vector<T> &input)
	{
		// fill second half of tree-array the leave-nodes with input values
		for (int tree_index = tree_size_ / 2, input_index = 0; tree_index < tree_size_; tree_index++, input_index++) {
			tree_[tree_index] = input[input_index];
		}
		// now fill the rest of the nodes
		for (int index = tree_size_ / 2 - 1; index > 0; --index) {
			tree_[index] = tree_[2 * index] + tree_[2 * index + 1];
		}
	}

	std::vector<T> tree_;
	int tree_size_{};
};

#endif //SEGMENT_TREE_H
