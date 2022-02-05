//
// Created by andreas on 05.02.22.
//

#include <stack>
#include "gtest/gtest.h"
#include "./../../stacks/stack_linked_list_based.h"

class SetupStack: public testing::Test
{
public:
	SetupStack()
	{
		reference_stack = new std::stack<int64_t>();
		for(const auto & element: input)
		{
			reference_stack->push(element);
		}
	}
protected:
	std::stack<int64_t> * reference_stack;
	std::vector<int64_t> input{1, 2, 3, 4, 5};
};

TEST_F(SetupStack, test_push_stack)
{
	auto stack = new StackLLB<int64_t>();

	for (const auto &element: input) {
		stack->push(element);
	}
	EXPECT_EQ(reference_stack->size()

}


