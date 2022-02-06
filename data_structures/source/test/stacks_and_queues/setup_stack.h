//
// Created by andreas on 05.02.22.
//

#ifndef SETUP_STACK_H
#define SETUP_STACK_H
#include <stack>
#include "gtest/gtest.h"

class SetupStack: public testing::Test
{
public:
	SetupStack()
	{
		reference_stack = new std::stack<int64_t>();
		for (const auto &element: input) {
			reference_stack->push(element);
		}
	}
protected:
	std::stack<int64_t> *reference_stack;
	std::vector<int64_t> input{1, 2, 3, 4, 5};
};

#endif //SETUP_STACK_H
