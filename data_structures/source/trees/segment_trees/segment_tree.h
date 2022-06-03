//
// Created by andreas on 03.06.22.
//

#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H
#include <vector>

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
	void update(size_t index, T val)
	{
		
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
	size_t tree_size_{};
};

#endif //SEGMENT_TREE_H
