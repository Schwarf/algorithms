//
// Created by andreas on 03.06.22.
//

#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H
#include <vector>
// Used only for fixed size arrays/vectors. Adding of elements not POSSIBLE!!!



template<typename T>
class SegmentTree{
public:
	SegmentTree(std::vector<T> & input)
	{
		if(input.empty())
			return;
		tree_size_ = 2*input.size();
		tree_ = std::vector<T>(tree_size_);
		build_tree(input);
	}
	void update(int index, T val)
	{
		// input is stored in second half of tree
		index += tree_size_/2;
		// update leaf
		tree_[index] = val;
		// update parents
		while(index >0)
		{
			int left = index;
			int right = index;

			if(index & 1)
				left = index - 1;
			else
				right = index + 1;
			tree_[index/2] = tree_[left] + tree_[right];
			index /= 2;
		}
	}

	T sum_range(int left_index, int right_index)
	{
		left_index += tree_size_/2;
		right_index += tree_size_/2;
		T sum{};
		while(left_index <= right_index)
		{
			if(left_index & 1)
				sum += tree_[left_index++];
			if(!(right_index & 1))
				sum += tree_[right_index++];
			left_index /=2;
			right_index /=2;
		}
		return sum;
	}



private:
	void build_tree(std::vector<T> & input)
	{
		// fill second half of tree with input
		for(int tree_index = tree_size_/2, input_index =0; tree_index < tree_size_; tree_index++, input_index++)
		{
			tree_[tree_index] = input[input_index];
		}
		for(int index = tree_size_/2 - 1 ; index > 0; --index)
		{
			tree_[index] = tree_[2*index] + tree_[2*index +1];
		}
	}

	std::vector<T> tree_;
	int tree_size_{};
};

#endif //SEGMENT_TREE_H
