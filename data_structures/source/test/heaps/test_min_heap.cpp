//
// Created by andreas on 30.05.26.
//

#include <gtest/gtest.h>
#include <vector>
#include "heaps/min_heap.h"

TEST(MinHeapTest, PeekThrowsForEmptyHeap)
{
    MinHeap<int> heap({});

    EXPECT_THROW(heap.peek(), std::runtime_error);
}

TEST(MinHeapTest, RemoveThrowsForEmptyHeap)
{
    MinHeap<int> heap({});

    EXPECT_THROW(heap.remove(), std::runtime_error);
}