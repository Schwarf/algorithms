//
// Created by andreas on 05.02.22.
//

#ifndef SETUP_STACK_H
#define SETUP_STACK_H
#include <queue>
#include "gtest/gtest.h"

class SetupQueue: public testing::Test
{
public:
	SetupQueue()
	{
		reference_queue = new std::queue<int64_t>();
		for (const auto &element: input) {
			reference_queue->push(element);
		}
	}
protected:
	std::queue<int64_t> *reference_queue;
	std::vector<int64_t> input{1, 2, 3, 4, 5};
};

#endif //SETUP_STACK_H
