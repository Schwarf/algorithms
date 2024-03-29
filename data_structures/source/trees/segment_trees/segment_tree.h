//
// Created by andreas on 03.06.22.
//

#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H
#include <vector>
//Given an integer array nums, handle multiple queries of the following types:
//
//Update the value of an element in nums.
//Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
//
//Implement the NumArray class:
//
//	NumArray(int[] nums) Initializes the object with the integer array nums.
//void update(int index, int val) Updates the value of nums[index] to be val.
//int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

// A Segment Tree, also known as a statistic tree,
// is a tree data structure used for storing information about intervals, or segments.
// It allows querying which of the stored segments contain a given point.
// It is, in principle, a static structure; that is, it’s a structure that cannot be modified once it’s built.

template<typename T>
class SegmentTree
{
public:
	explicit SegmentTree(std::vector<T> &input)
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
		while (index > 0) {
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
		// fill second half of tree with input
		for (int tree_index = tree_size_ / 2, input_index = 0; tree_index < tree_size_; tree_index++, input_index++) {
			tree_[tree_index] = input[input_index];
		}
		for (int index = tree_size_ / 2 - 1; index > 0; --index) {
			tree_[index] = tree_[2 * index] + tree_[2 * index + 1];
		}
	}

	std::vector<T> tree_;
	int tree_size_{};
};

#endif //SEGMENT_TREE_H
