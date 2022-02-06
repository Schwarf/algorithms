//
// Created by andreas on 06.02.22.
//

#include "setup_queue.h"
#include "./../../stacks_and_queues/queue_linked_list_based.h"

TEST_F(SetupQueue, test_enqueue)
{
	auto queue = new QueueLLB<int64_t>();
	EXPECT_TRUE(queue->is_empty());
	for(const auto & element: input)
	{
		queue->enqueue(element);
	}
	EXPECT_FALSE(queue->is_empty());
	EXPECT_EQ(queue->size(), reference_queue->size());
}


TEST_F(SetupQueue, test_dequeue)
{
	auto queue = new QueueLLB<int64_t>();
	for(const auto & element: input)
	{
		queue->enqueue(element);
	}
	auto help = reference_queue->size();
	for(size_t index = 0; index < help ; index++)
	{
		EXPECT_EQ(reference_queue->front(), queue->dequeue());
		reference_queue->pop();
		EXPECT_EQ(reference_queue->size(), queue->size());
	}
	EXPECT_TRUE(queue->is_empty());

}

TEST_F(SetupQueue, test_front)
{
	auto queue = new QueueLLB<int64_t>();
	for(const auto & element: input)
	{
		queue->enqueue(element);
	}
	auto help = reference_queue->size();
	auto reference_element = reference_queue->front();
	EXPECT_EQ(reference_element, queue->front());
	reference_queue->pop();
	queue->dequeue();
	EXPECT_EQ(reference_queue->front(), queue->front());
	EXPECT_NE(reference_element, queue->front());
	EXPECT_FALSE(queue->is_empty());
}

TEST_F(SetupQueue, test_back)
{
	auto queue = new QueueLLB<int64_t>();
	for(const auto & element: input)
	{
		queue->enqueue(element);
	}
	EXPECT_EQ(reference_queue->back(), queue->back());
	EXPECT_FALSE(queue->is_empty());
}
