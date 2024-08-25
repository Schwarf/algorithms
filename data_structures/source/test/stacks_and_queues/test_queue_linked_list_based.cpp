//
// Created by andreas on 06.02.22.
//

#include "setup_queue.h"
#include "stacks_and_queues/queue_linked_list_based.h"

TEST_F(SetupQueue, test_enqueue) {
    auto queue = new QueueLLB<int64_t>();
    EXPECT_TRUE(queue->is_empty());
    for (const auto &element: input) {
        queue->enqueue(element);
    }
    EXPECT_FALSE(queue->is_empty());
    EXPECT_EQ(queue->size(), reference_queue->size());
}


TEST_F(SetupQueue, test_dequeue) {
    auto queue = new QueueLLB<int64_t>();
    for (const auto &element: input) {
        queue->enqueue(element);
    }
    auto help = reference_queue->size();
    for (size_t index = 0; index < help; index++) {
        EXPECT_EQ(reference_queue->front(), queue->dequeue());
        reference_queue->pop();
        EXPECT_EQ(reference_queue->size(), queue->size());
    }
    EXPECT_TRUE(queue->is_empty());

}

TEST_F(SetupQueue, test_front) {
    auto queue = new QueueLLB<int64_t>();
    for (const auto &element: input) {
        queue->enqueue(element);
    }
    auto reference_element = reference_queue->front();
    EXPECT_EQ(reference_element, queue->front());
    reference_queue->pop();
    queue->dequeue();
    EXPECT_EQ(reference_queue->front(), queue->front());
    EXPECT_NE(reference_element, queue->front());
    EXPECT_FALSE(queue->is_empty());
}

TEST_F(SetupQueue, test_back) {
    auto queue = new QueueLLB<int64_t>();
    for (const auto &element: input) {
        queue->enqueue(element);
    }
    EXPECT_EQ(reference_queue->back(), queue->back());
    EXPECT_FALSE(queue->is_empty());
}


TEST_F(SetupQueue, test_throw_dequeue_if_queue_is_empty) {
    auto queue = new QueueLLB<int64_t>();
    std::string message = "Can not dequeue. The queue is empty.";
    try {
        queue->dequeue();
        FAIL() << "Queue is empty";
    }
    catch (std::out_of_range const &err) {
        EXPECT_EQ(err.what(), message);
    }
}


TEST_F(SetupQueue, test_throw_front_if_queue_is_empty) {
    auto queue = new QueueLLB<int64_t>();
    std::string message = "Can not return front element. The queue is empty.";
    try {
        queue->front();
        FAIL() << "Queue is empty";
    }
    catch (std::out_of_range const &err) {
        EXPECT_EQ(err.what(), message);
    }
}


TEST_F(SetupQueue, test_throw_back_if_queue_is_empty) {
    auto queue = new QueueLLB<int64_t>();
    std::string message = "Can not return back element. The queue is empty.";
    try {
        queue->back();
        FAIL() << "Queue is empty";
    }
    catch (std::out_of_range const &err) {
        EXPECT_EQ(err.what(), message);
    }
}


TEST_F(SetupQueue, test_enqeue_and_dequeue_and_all) {
    auto queue = new QueueLLB<int64_t>();
    for (const auto &element: input) {
        queue->enqueue(element);
    }
    auto help = reference_queue->size();
    for (size_t index = 0; index < help; index++) {
        EXPECT_EQ(reference_queue->front(), queue->dequeue());
        reference_queue->pop();
    }
    int64_t value1{1289012};
    int64_t value2{2190788};
    int64_t value3{28};

    queue->enqueue(value1);
    reference_queue->push(value1);
    EXPECT_EQ(queue->front(), reference_queue->front());
    EXPECT_EQ(queue->back(), reference_queue->back());
    EXPECT_EQ(queue->back(), queue->front());
    EXPECT_EQ(queue->size(), reference_queue->size());
    queue->enqueue(value2);
    reference_queue->push(value2);
    EXPECT_EQ(queue->front(), reference_queue->front());
    EXPECT_EQ(queue->back(), reference_queue->back());
    EXPECT_NE(queue->back(), queue->front());
    queue->dequeue();
    reference_queue->pop();
    EXPECT_EQ(queue->size(), reference_queue->size());
    queue->enqueue(value3);
    reference_queue->push(value3);
    EXPECT_EQ(queue->front(), reference_queue->front());
    EXPECT_EQ(queue->back(), reference_queue->back());
    EXPECT_NE(queue->back(), queue->front());

}

