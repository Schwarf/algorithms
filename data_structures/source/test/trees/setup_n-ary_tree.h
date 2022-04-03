//
// Created by andreas on 03.04.22.
//

#ifndef SETUP_N_ARY_TREE_H
#define SETUP_N_ARY_TREE_H
#include "gtest/gtest.h"
#include <vector>
#include "./../../trees/n-ary_tree.h"

template <typename T>
class HelperClass
{
public:
	void operator()(T value)
	{
		result_.push_back(value);
	}
	std::vector<T> result()
	{
		return result_;
	}

private:
	std::vector<T> result_;

};


class SetupN_aryTree: public testing::Test
{
public:
	SetupN_aryTree() = default;
protected:
	std::vector<int> insertion{25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};
	std::vector<int> inorder{4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90};
	std::vector<int> preorder{25, 15, 10, 4, 12, 22, 18, 24, 50, 35, 31, 44, 70, 66, 90};
	std::vector<int> postorder{4, 12, 10, 18, 24, 22, 15, 31, 44, 35, 66, 90, 70, 50, 25};
};

#endif //SETUP_N_ARY_TREE_H
