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

TEST(MinHeapTest, PeekReturnsSmallestElementAfterConstruction)
{
    MinHeap<int> heap({48, 12, 24, 7, 18, 3, 31});

    EXPECT_EQ(heap.peek(), 3);
}

TEST(MinHeapTest, RemoveReturnsElementsInSortedOrder)
{
    MinHeap<int> heap({48, 12, 24, 7, 18, 3, 31});

    EXPECT_EQ(heap.remove(), 3);
    EXPECT_EQ(heap.remove(), 7);
    EXPECT_EQ(heap.remove(), 12);
    EXPECT_EQ(heap.remove(), 18);
    EXPECT_EQ(heap.remove(), 24);
    EXPECT_EQ(heap.remove(), 31);
    EXPECT_EQ(heap.remove(), 48);
}

TEST(MinHeapTest, InsertMaintainsMinHeapProperty)
{
    MinHeap<int> heap({10, 20, 30});

    EXPECT_EQ(heap.peek(), 10);

    heap.insert(5);
    EXPECT_EQ(heap.peek(), 5);

    heap.insert(1);
    EXPECT_EQ(heap.peek(), 1);

    EXPECT_EQ(heap.remove(), 1);
    EXPECT_EQ(heap.remove(), 5);
    EXPECT_EQ(heap.remove(), 10);
    EXPECT_EQ(heap.remove(), 20);
    EXPECT_EQ(heap.remove(), 30);
}

TEST(MinHeapTest, WorksWithEmptyInitialVectorAndInsert)
{
    MinHeap<int> heap({});

    heap.insert(42);
    EXPECT_EQ(heap.peek(), 42);

    heap.insert(7);
    EXPECT_EQ(heap.peek(), 7);

    heap.insert(100);
    EXPECT_EQ(heap.peek(), 7);

    EXPECT_EQ(heap.remove(), 7);
    EXPECT_EQ(heap.remove(), 42);
    EXPECT_EQ(heap.remove(), 100);
}

TEST(MinHeapTest, WorksWithDuplicateValues)
{
    MinHeap<int> heap({5, 1, 3, 1, 2, 5});

    EXPECT_EQ(heap.remove(), 1);
    EXPECT_EQ(heap.remove(), 1);
    EXPECT_EQ(heap.remove(), 2);
    EXPECT_EQ(heap.remove(), 3);
    EXPECT_EQ(heap.remove(), 5);
    EXPECT_EQ(heap.remove(), 5);
}

TEST(MinHeapTest, WorksWithNegativeValues)
{
    MinHeap<int> heap({0, -10, 5, -3, 2});

    EXPECT_EQ(heap.peek(), -10);

    EXPECT_EQ(heap.remove(), -10);
    EXPECT_EQ(heap.remove(), -3);
    EXPECT_EQ(heap.remove(), 0);
    EXPECT_EQ(heap.remove(), 2);
    EXPECT_EQ(heap.remove(), 5);
}

TEST(MinHeapTest, WorksWithSingleElement)
{
    MinHeap<int> heap({42});

    EXPECT_EQ(heap.peek(), 42);
    EXPECT_EQ(heap.remove(), 42);
}

TEST(MinHeapTest, InterleavedInsertAndRemoveWorksCorrectly)
{
    MinHeap<int> heap({8, 12, 20});

    EXPECT_EQ(heap.remove(), 8);

    heap.insert(5);
    heap.insert(15);

    EXPECT_EQ(heap.remove(), 5);
    EXPECT_EQ(heap.remove(), 12);

    heap.insert(1);

    EXPECT_EQ(heap.remove(), 1);
    EXPECT_EQ(heap.remove(), 15);
    EXPECT_EQ(heap.remove(), 20);
}