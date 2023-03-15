//
// Created by andreas on 25.09.22.
//
#include "gtest/gtest.h"
#include "binary_search_tree/avl_tree.h"
#include <vector>
#include <random>

class SetupAVLTree: public testing::Test
{
public:
	explicit SetupAVLTree()
		:
		random_engine_{std::random_device{}()}
	{
		ascending_order = descending_order;
		std::reverse(ascending_order.begin(), ascending_order.end());
	}
protected:

	int get_one_random_number(const int &lower_bound, const int &upper_bound)
	{
		int_distribution_ = std::uniform_int_distribution{lower_bound, upper_bound};
		return int_distribution_(random_engine_);
	}

	std::vector<int> get_N_random_numbers(const int &lower_bound, const int &upper_bound, const size_t &size)
	{
		int_distribution_ = std::uniform_int_distribution{lower_bound, upper_bound};
		std::vector<int> result;
		for (size_t i{}; i < size; ++i) {
			result.push_back(int_distribution_(random_engine_));
		}
		return result;
	}

	std::vector<int> descending_order{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6};
	std::vector<int> ascending_order;
	int expected_height = 5;
	int reduced_expected_height = 4;
private:
	std::mt19937 random_engine_;
	std::uniform_int_distribution<int> int_distribution_;
};

TEST_F(SetupAVLTree, test_insert_descending_order)
{
	auto avl_tree = AVLTree<int>();
	for (const auto &element: descending_order)
		avl_tree.insert(element);
	EXPECT_EQ(avl_tree.height(), expected_height);
	EXPECT_EQ(avl_tree.number_of_nodes(), descending_order.size());
	auto result = avl_tree.get_vector_inorder();
	EXPECT_EQ(result, ascending_order);
	EXPECT_TRUE(avl_tree.is_value_in_tree(descending_order[0]));
	int value_not_in_tree = 12;
	EXPECT_FALSE(avl_tree.is_value_in_tree(value_not_in_tree));
}


TEST_F(SetupAVLTree, test_insert_ascending_order)
{
	auto avl_tree = AVLTree<int>();
	for (const auto &element: ascending_order)
		avl_tree.insert(element);
	EXPECT_EQ(avl_tree.height(), expected_height);
	EXPECT_EQ(avl_tree.number_of_nodes(), descending_order.size());
	auto result = avl_tree.get_vector_inorder();
	EXPECT_EQ(result, ascending_order);
	EXPECT_TRUE(avl_tree.is_value_in_tree(ascending_order[0]));
	int value_not_in_tree = -12;
	EXPECT_FALSE(avl_tree.is_value_in_tree(value_not_in_tree));
}


TEST_F(SetupAVLTree, test_deleting_biggest_values)
{
	auto avl_tree = AVLTree<int>();
	for (const auto &element: ascending_order)
		avl_tree.insert(element);
	for (int i{}; i < descending_order.size() / 2; ++i) {
		avl_tree.delete_node_with_value(descending_order[i]);
	}
	EXPECT_EQ(avl_tree.height(), reduced_expected_height);
	EXPECT_EQ(avl_tree.number_of_nodes(), descending_order.size() - (descending_order.size() / 2));
	auto result = avl_tree.get_vector_inorder();
	for (int i{}; i < ascending_order.size() / 2; ++i) {
		EXPECT_EQ(result[i], ascending_order[i]);
	}
}

TEST_F(SetupAVLTree, test_deleting_one_value_in_between)
{
	auto avl_tree = AVLTree<int>();
	for (const auto &element: ascending_order)
		avl_tree.insert(element);
	int index = 5;
	EXPECT_TRUE(avl_tree.is_value_in_tree(ascending_order[index]));
	avl_tree.delete_node_with_value(ascending_order[index]);
	EXPECT_FALSE(avl_tree.is_value_in_tree(ascending_order[index]));
	auto result = avl_tree.get_vector_inorder();
	ascending_order.erase(std::remove(ascending_order.begin(), ascending_order.end(), ascending_order[index]),
						  ascending_order.end());
	EXPECT_EQ(avl_tree.number_of_nodes(), descending_order.size() - 1);
	for (int i{}; i < ascending_order.size(); ++i) {
		if (i == index)
			continue;
		EXPECT_EQ(result[i], ascending_order[i]);
	}
}

TEST_F(SetupAVLTree, test_deleting_one_value_in_between_and_inserting_it_again)
{
	auto avl_tree = AVLTree<int>();
	for (const auto &element: ascending_order)
		avl_tree.insert(element);
	int index = 3;
	EXPECT_TRUE(avl_tree.is_value_in_tree(ascending_order[index]));
	avl_tree.delete_node_with_value(ascending_order[index]);
	EXPECT_FALSE(avl_tree.is_value_in_tree(ascending_order[index]));
	EXPECT_EQ(avl_tree.number_of_nodes(), descending_order.size() - 1);
	avl_tree.insert(ascending_order[index]);
	EXPECT_TRUE(avl_tree.is_value_in_tree(ascending_order[index]));
	EXPECT_EQ(avl_tree.number_of_nodes(), descending_order.size());
	auto result = avl_tree.get_vector_inorder();
	for (int i{}; i < ascending_order.size(); ++i) {
		EXPECT_EQ(result[i], ascending_order[i]);
	}
}

TEST_F(SetupAVLTree, test_random_inserting)
{
	auto avl_tree = AVLTree<int>();
	int index{};
	int limit{1000};
	auto random_numbers = get_N_random_numbers(-1000000, 1000000, limit);
	std::set<int> expected_result;
	for (const auto &number: random_numbers) {
		avl_tree.insert(number);
		expected_result.insert(number);
	}

	auto result = avl_tree.get_vector_inorder();

	index = 0;
	EXPECT_EQ(avl_tree.number_of_nodes(), 1000);
	for (

		const auto &element

		: expected_result) {
		EXPECT_EQ(result[index], element);
		index++;
	}
}

TEST_F(SetupAVLTree, test_random_inserting_and_random_deleting)
{
	auto avl_tree = AVLTree<int>();
	int index{};
	int limit{1000};
	int value{};
	std::set<int> expected_result;
	std::vector<int> help;
	while (index < limit) {
		value = get_one_random_number(-1000000, 1000000);
		avl_tree.insert(value);
		help.push_back(value);
		expected_result.insert(value);
		index++;
	}
	auto result = avl_tree.get_vector_inorder();
	index = 0;
	EXPECT_EQ(avl_tree.number_of_nodes(), 1000);
	for (const auto &element: expected_result) {
		EXPECT_EQ(result[index], element);
		index++;
	}
	int delete_limit = 50;
	for (int i = 0; i < delete_limit; ++i) {
		index = get_one_random_number(0, help.size());
		avl_tree.delete_node_with_value(help[index]);
		expected_result.erase(help[index]);
	}
	index = 0;
	EXPECT_EQ(avl_tree.number_of_nodes(), 950);
	result = avl_tree.get_vector_inorder();
	for (const auto &element: expected_result) {
		EXPECT_EQ(result[index], element);
		index++;
	}
}
