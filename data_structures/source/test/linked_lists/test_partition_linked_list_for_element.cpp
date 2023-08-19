//
// Created by andreas on 19.03.23.
//

#include "setup_singly_linked_lists.h"
#include "linked_lists/partition_linked_list_for_element.h"

TEST_F(SetupSinglyLinkedLists, partition_element1)
{
	std::vector<int> input{2, 8, 7, 9, 5, 1, 2, 3, 4, 9};
	auto head = get_single_list_from_vector(input);
	auto node = head;
	size_t size{};
	while (node) {
		size++;
		node = node->next;
	}
	EXPECT_EQ(size, input.size());
	int partition_element{5};
	int number_of_elements_smaller{5};
	int number_of_elements_greater_equal{5};
	head = partition_linked_list_for_element(head, partition_element);
	node = head;
	int counter{};
	while (node && counter < number_of_elements_smaller) {
		counter++;
		EXPECT_TRUE(node->value < partition_element);
		node = node->next;
	}
	counter = 0;
	while (node && counter < number_of_elements_greater_equal) {
		counter++;
		EXPECT_TRUE(node->value >= partition_element);
		node = node->next;
	}

}


TEST_F(SetupSinglyLinkedLists, partition_element2)
{
	std::vector<int> input{8, 8, 7, 9, 5, 1, 2, 3, 4, 9};
	auto head = get_single_list_from_vector(input);
	auto node = head;
	size_t size{};
	while (node) {
		size++;
		node = node->next;
	}
	EXPECT_EQ(size, input.size());
	int partition_element{5};
	int number_of_elements_smaller{4};
	int number_of_elements_greater_equal{6};
	head = partition_linked_list_for_element(head, partition_element);
	node = head;
	int counter{};
	while (node && counter < number_of_elements_smaller) {
		counter++;
		EXPECT_TRUE(node->value < partition_element);
		node = node->next;
	}
	counter = 0;
	while (node && counter < number_of_elements_greater_equal) {
		counter++;
		EXPECT_TRUE(node->value >= partition_element);
		node = node->next;
	}

}


TEST_F(SetupSinglyLinkedLists, partition_element_just_2_elements)
{
	std::vector<int> input{10, 5};
	auto head = get_single_list_from_vector(input);
	auto node = head;
	size_t size{};
	while (node) {
		size++;
		node = node->next;
	}
	EXPECT_EQ(size, input.size());
	int partition_element{5};
	head = partition_linked_list_for_element(head, partition_element);
	int index{};
	while (head) {
		EXPECT_EQ(head->value, input[index++]);
		head = head->next;
	}
}

TEST_F(SetupSinglyLinkedLists, partition_element_just_2_elements2)
{
	std::vector<int> input{4, 5};
	auto head = get_single_list_from_vector(input);
	auto node = head;
	size_t size{};
	while (node) {
		size++;
		node = node->next;
	}
	EXPECT_EQ(size, input.size());
	int partition_element{5};
	head = partition_linked_list_for_element(head, partition_element);
	int index{};
	while (head) {
		EXPECT_EQ(head->value, input[index++]);
		head = head->next;
	}
}


TEST_F(SetupSinglyLinkedLists, partition_element_just_2_elements3)
{
	std::vector<int> input{5, 1};
	auto head = get_single_list_from_vector(input);
	auto node = head;
	size_t size{};
	while (node) {
		size++;
		node = node->next;
	}
	EXPECT_EQ(size, input.size());
	int partition_element{5};
	head = partition_linked_list_for_element(head, partition_element);
	int index{};
	std::ranges::reverse(input);
	while (head) {
		EXPECT_EQ(head->value, input[index++]);
		head = head->next;
	}
}


TEST_F(SetupSinglyLinkedLists, partition_element_in_order1)
{
	const std::vector<int> input{2, 8, 7, 9, 5, 1, 2, 3, 4, 9};
	auto head = get_single_list_from_vector(input);
	constexpr int partition_element{5};
	head = partition_linked_list_for_element_and_keep_order(head, partition_element);
	const std::vector<int> expected_output{2, 1, 2, 3, 4, 8, 7, 9, 5, 9};
	int index{};
	while (head) {
		EXPECT_EQ(head->value, expected_output.at(index++));
		head = head->next;
	}
}

TEST_F(SetupSinglyLinkedLists, partition_element_in_order2)
{
	const std::vector<int> input{1, 4, 3, 2, 5, 2};
	auto head = get_single_list_from_vector(input);
	constexpr int partition_element{3};
	head = partition_linked_list_for_element_and_keep_order(head, partition_element);
	const std::vector<int> expected_output{1, 2, 2, 4, 3, 5};
	int index{};
	while (head) {
		EXPECT_EQ(head->value, expected_output.at(index++));
		head = head->next;
	}
}

TEST_F(SetupSinglyLinkedLists, partition_element_in_order3)
{
	const std::vector<int> input{2, 1};
	auto head = get_single_list_from_vector(input);
	constexpr int partition_element{2};
	head = partition_linked_list_for_element_and_keep_order(head, partition_element);
	const std::vector<int> expected_output{1, 2};
	int index{};
	while (head) {
		EXPECT_EQ(head->value, expected_output.at(index++));
		head = head->next;
	}
}

TEST_F(SetupSinglyLinkedLists, partition_element_in_order4)
{
	const std::vector<int> input{1};
	auto head = get_single_list_from_vector(input);
	constexpr int partition_element{2};
	head = partition_linked_list_for_element_and_keep_order(head, partition_element);
	const std::vector<int> expected_output{1};
	int index{};
	while (head) {
		EXPECT_EQ(head->value, expected_output.at(index++));
		head = head->next;
	}
}

TEST_F(SetupSinglyLinkedLists, partition_element_in_order5)
{
	const std::vector<int> input{8, 8, 7, 9, 5, 1, 2, 3, 4, 9};
	auto head = get_single_list_from_vector(input);
	constexpr int partition_element{8};
	head = partition_linked_list_for_element_and_keep_order(head, partition_element);
	const std::vector<int> expected_output{7, 5, 1, 2, 3, 4, 8, 8, 9, 9};
	int index{};
	while (head) {
		EXPECT_EQ(head->value, expected_output.at(index++));
		head = head->next;
	}
}
