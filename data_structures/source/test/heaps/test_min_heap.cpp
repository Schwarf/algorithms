//
// Created by andreas on 30.05.26.
//

#include <gtest/gtest.h>
#include "heaps/min_heap.h"

template <typename T>
class MinHeapTypedTest : public ::testing::Test
{
};

using NumericMinHeapTypes = ::testing::Types<int, long, double>;

TYPED_TEST_SUITE(MinHeapTypedTest, NumericMinHeapTypes);

TYPED_TEST(MinHeapTypedTest, PeekThrowsForEmptyHeap)
{
    using T = TypeParam;

    MinHeap<T> heap(std::vector<T>{});

    EXPECT_THROW(heap.peek(), std::runtime_error);
}

TYPED_TEST(MinHeapTypedTest, RemoveThrowsForEmptyHeap)
{
    using T = TypeParam;

    MinHeap<T> heap(std::vector<T>{});

    EXPECT_THROW(heap.remove(), std::runtime_error);
}

TYPED_TEST(MinHeapTypedTest, PeekReturnsSmallestElementAfterConstruction)
{
    using T = TypeParam;

    MinHeap<T> heap({T{48}, T{12}, T{24}, T{7}, T{18}, T{3}, T{31}});

    EXPECT_EQ(heap.peek(), T{3});
}

TYPED_TEST(MinHeapTypedTest, RemoveReturnsElementsInSortedOrder)
{
    using T = TypeParam;

    MinHeap<T> heap({T{48}, T{12}, T{24}, T{7}, T{18}, T{3}, T{31}});

    EXPECT_EQ(heap.remove(), T{3});
    EXPECT_EQ(heap.remove(), T{7});
    EXPECT_EQ(heap.remove(), T{12});
    EXPECT_EQ(heap.remove(), T{18});
    EXPECT_EQ(heap.remove(), T{24});
    EXPECT_EQ(heap.remove(), T{31});
    EXPECT_EQ(heap.remove(), T{48});
}

TYPED_TEST(MinHeapTypedTest, InsertMaintainsMinHeapProperty)
{
    using T = TypeParam;

    MinHeap<T> heap({T{10}, T{20}, T{30}});

    EXPECT_EQ(heap.peek(), T{10});

    heap.insert(T{5});
    EXPECT_EQ(heap.peek(), T{5});

    heap.insert(T{1});
    EXPECT_EQ(heap.peek(), T{1});

    EXPECT_EQ(heap.remove(), T{1});
    EXPECT_EQ(heap.remove(), T{5});
    EXPECT_EQ(heap.remove(), T{10});
    EXPECT_EQ(heap.remove(), T{20});
    EXPECT_EQ(heap.remove(), T{30});
}

TYPED_TEST(MinHeapTypedTest, WorksWithEmptyInitialVectorAndInsert)
{
    using T = TypeParam;

    MinHeap<T> heap(std::vector<T>{});

    heap.insert(T{42});
    EXPECT_EQ(heap.peek(), T{42});

    heap.insert(T{7});
    EXPECT_EQ(heap.peek(), T{7});

    heap.insert(T{100});
    EXPECT_EQ(heap.peek(), T{7});

    EXPECT_EQ(heap.remove(), T{7});
    EXPECT_EQ(heap.remove(), T{42});
    EXPECT_EQ(heap.remove(), T{100});
}

TYPED_TEST(MinHeapTypedTest, WorksWithDuplicateValues)
{
    using T = TypeParam;

    MinHeap<T> heap({T{5}, T{1}, T{3}, T{1}, T{2}, T{5}});

    EXPECT_EQ(heap.remove(), T{1});
    EXPECT_EQ(heap.remove(), T{1});
    EXPECT_EQ(heap.remove(), T{2});
    EXPECT_EQ(heap.remove(), T{3});
    EXPECT_EQ(heap.remove(), T{5});
    EXPECT_EQ(heap.remove(), T{5});
}

TYPED_TEST(MinHeapTypedTest, WorksWithNegativeValues)
{
    using T = TypeParam;

    MinHeap<T> heap({T{0}, T{-10}, T{5}, T{-3}, T{2}});

    EXPECT_EQ(heap.peek(), T{-10});

    EXPECT_EQ(heap.remove(), T{-10});
    EXPECT_EQ(heap.remove(), T{-3});
    EXPECT_EQ(heap.remove(), T{0});
    EXPECT_EQ(heap.remove(), T{2});
    EXPECT_EQ(heap.remove(), T{5});
}

TYPED_TEST(MinHeapTypedTest, WorksWithSingleElement)
{
    using T = TypeParam;

    MinHeap<T> heap({T{42}});

    EXPECT_EQ(heap.peek(), T{42});
    EXPECT_EQ(heap.remove(), T{42});
}

TYPED_TEST(MinHeapTypedTest, InterleavedInsertAndRemoveWorksCorrectly)
{
    using T = TypeParam;

    MinHeap<T> heap({T{8}, T{12}, T{20}});

    EXPECT_EQ(heap.remove(), T{8});

    heap.insert(T{5});
    heap.insert(T{15});

    EXPECT_EQ(heap.remove(), T{5});
    EXPECT_EQ(heap.remove(), T{12});

    heap.insert(T{1});

    EXPECT_EQ(heap.remove(), T{1});
    EXPECT_EQ(heap.remove(), T{15});
    EXPECT_EQ(heap.remove(), T{20});
}
