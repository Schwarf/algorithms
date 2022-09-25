//
// Created by andreas on 25.09.22.
//
#include "gtest/gtest.h"
#include "./../../binary_search_tree/avl_tree.h"
#include <vector>
#include <algorithm>

class SetupAVLTree: public testing::Test
{
public:
	explicit SetupAVLTree()
	{
		ascending_order = descending_order;
		std::reverse(ascending_order.begin(), ascending_order.end());
	}
protected:
	std::vector<int> descending_order{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6};
	std::vector<int> ascending_order;
	int expected_height = 5;
};

TEST_F(SetupAVLTree, test_descending_order)
{
	auto avl_tree = AVLTree<int>();
	for(const auto & element: descending_order)
		avl_tree.insert(element);
	EXPECT_EQ(avl_tree.height(), expected_height);
	auto result = avl_tree.write_to_vector_inorder();
	EXPECT_EQ(result, ascending_order);
}


TEST_F(SetupAVLTree, test_ascending_order)
{
	auto avl_tree = AVLTree<int>();
	for(const auto & element: ascending_order)
		avl_tree.insert(element);
	EXPECT_EQ(avl_tree.height(), expected_height);
	auto result = avl_tree.write_to_vector_inorder();
	EXPECT_EQ(result, ascending_order);
}
