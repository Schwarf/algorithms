//
// Created by andreas on 29.01.22.
//

#include <algorithm>
#include "gtest/gtest.h"
#include "./../../linked_lists/single_linked_list.h"

class SetupLinkedList: public testing::Test
{
public:
	SetupLinkedList()
	{
		linked_list = new SingleLinkedList<int64_t>();
	}
protected:
	SingleLinkedList<int64_t> * linked_list;
	std::vector<int64_t> input{1,2,3,4,5};
};


TEST_F(SetupLinkedList, test_add_at_head)
{
	for(const auto & element : input)
	{
		linked_list->add_at_head(element);
	}
	int64_t value{};
	std::reverse(input.begin(), input.end());
	for(size_t index =0; index <  input.size(); ++index)
	{
		linked_list->get(index, value);
		EXPECT_EQ(value, input[index]);
	}
}

TEST_F(SetupLinkedList, test_add_at_tail)
{
	for(const auto & element : input)
	{
		linked_list->add_at_tail(element);
	}
	int64_t value{};

	for(size_t index =0; index <  input.size(); ++index)
	{
		linked_list->get(index, value);
		EXPECT_EQ(value, input[index]);
	}
}


TEST_F(SetupLinkedList, test_add_at_index_1_and_index_3)
{
	for(const auto & element : input)
	{
		linked_list->add_at_tail(element);
	}
	int64_t value{};

	for(size_t index =0; index <  input.size(); ++index)
	{
		linked_list->get(index, value);
		EXPECT_EQ(value, input[index]);
	}
}

