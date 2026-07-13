//
// Created by andreas on 30.05.26.
//

//
// Created by andreas on 30.05.26.
//

#include <gtest/gtest.h>

#include <compare>
#include <stdexcept>
#include <string>
#include <vector>

#include "heaps/max_heap.h"

template <typename T>
class MaxHeapTypedTest : public ::testing::Test
{
};

using NumericMaxHeapTypes = ::testing::Types<int, long, double>;

TYPED_TEST_SUITE(MaxHeapTypedTest, NumericMaxHeapTypes);

TYPED_TEST(MaxHeapTypedTest, PeekThrowsForEmptyHeap)
{
    using T = TypeParam;

    MaxHeap<T> heap(std::vector<T>{});

    EXPECT_THROW(heap.peek(), std::runtime_error);
}

TYPED_TEST(MaxHeapTypedTest, RemoveThrowsForEmptyHeap)
{
    using T = TypeParam;

    MaxHeap<T> heap(std::vector<T>{});

    EXPECT_THROW(heap.remove(), std::runtime_error);
}

TYPED_TEST(MaxHeapTypedTest, PeekReturnsLargestElementAfterConstruction)
{
    using T = TypeParam;

    MaxHeap<T> heap({T{48}, T{12}, T{24}, T{7}, T{18}, T{3}, T{31}});

    EXPECT_EQ(heap.peek(), T{48});
}

TYPED_TEST(MaxHeapTypedTest, RemoveReturnsElementsInDescendingSortedOrder)
{
    using T = TypeParam;

    MaxHeap<T> heap({T{48}, T{12}, T{24}, T{7}, T{18}, T{3}, T{31}});

    EXPECT_EQ(heap.remove(), T{48});
    EXPECT_EQ(heap.remove(), T{31});
    EXPECT_EQ(heap.remove(), T{24});
    EXPECT_EQ(heap.remove(), T{18});
    EXPECT_EQ(heap.remove(), T{12});
    EXPECT_EQ(heap.remove(), T{7});
    EXPECT_EQ(heap.remove(), T{3});
}

TYPED_TEST(MaxHeapTypedTest, InsertMaintainsMaxHeapProperty)
{
    using T = TypeParam;

    MaxHeap<T> heap({T{10}, T{20}, T{30}});

    EXPECT_EQ(heap.peek(), T{30});

    heap.insert(T{40});
    EXPECT_EQ(heap.peek(), T{40});

    heap.insert(T{50});
    EXPECT_EQ(heap.peek(), T{50});

    EXPECT_EQ(heap.remove(), T{50});
    EXPECT_EQ(heap.remove(), T{40});
    EXPECT_EQ(heap.remove(), T{30});
    EXPECT_EQ(heap.remove(), T{20});
    EXPECT_EQ(heap.remove(), T{10});
}

TYPED_TEST(MaxHeapTypedTest, WorksWithEmptyInitialVectorAndInsert)
{
    using T = TypeParam;

    MaxHeap<T> heap(std::vector<T>{});

    heap.insert(T{42});
    EXPECT_EQ(heap.peek(), T{42});

    heap.insert(T{7});
    EXPECT_EQ(heap.peek(), T{42});

    heap.insert(T{100});
    EXPECT_EQ(heap.peek(), T{100});

    EXPECT_EQ(heap.remove(), T{100});
    EXPECT_EQ(heap.remove(), T{42});
    EXPECT_EQ(heap.remove(), T{7});
}

TYPED_TEST(MaxHeapTypedTest, WorksWithDuplicateValues)
{
    using T = TypeParam;

    MaxHeap<T> heap({T{5}, T{1}, T{3}, T{1}, T{2}, T{5}});

    EXPECT_EQ(heap.remove(), T{5});
    EXPECT_EQ(heap.remove(), T{5});
    EXPECT_EQ(heap.remove(), T{3});
    EXPECT_EQ(heap.remove(), T{2});
    EXPECT_EQ(heap.remove(), T{1});
    EXPECT_EQ(heap.remove(), T{1});
}

TYPED_TEST(MaxHeapTypedTest, WorksWithNegativeValues)
{
    using T = TypeParam;

    MaxHeap<T> heap({T{0}, T{-10}, T{5}, T{-3}, T{2}});

    EXPECT_EQ(heap.peek(), T{5});

    EXPECT_EQ(heap.remove(), T{5});
    EXPECT_EQ(heap.remove(), T{2});
    EXPECT_EQ(heap.remove(), T{0});
    EXPECT_EQ(heap.remove(), T{-3});
    EXPECT_EQ(heap.remove(), T{-10});
}

TYPED_TEST(MaxHeapTypedTest, WorksWithSingleElement)
{
    using T = TypeParam;

    MaxHeap<T> heap({T{42}});

    EXPECT_EQ(heap.peek(), T{42});
    EXPECT_EQ(heap.remove(), T{42});
}

TYPED_TEST(MaxHeapTypedTest, InterleavedInsertAndRemoveWorksCorrectly)
{
    using T = TypeParam;

    MaxHeap<T> heap({T{8}, T{12}, T{20}});

    EXPECT_EQ(heap.remove(), T{20});

    heap.insert(T{5});
    heap.insert(T{15});

    EXPECT_EQ(heap.remove(), T{15});
    EXPECT_EQ(heap.remove(), T{12});

    heap.insert(T{100});

    EXPECT_EQ(heap.remove(), T{100});
    EXPECT_EQ(heap.remove(), T{8});
    EXPECT_EQ(heap.remove(), T{5});
}

TEST(MaxHeapTest, WorksWithStrings)
{
    MaxHeap<std::string> heap({"banana", "apple", "cherry", "date"});

    EXPECT_EQ(heap.peek(), "date");

    EXPECT_EQ(heap.remove(), "date");
    EXPECT_EQ(heap.remove(), "cherry");
    EXPECT_EQ(heap.remove(), "banana");
    EXPECT_EQ(heap.remove(), "apple");
}

struct Job
{
    int priority;
    int id;

    bool operator==(const Job&) const = default;

    // Compares in declaration order:
    // first priority, then id.
    auto operator<=>(const Job&) const = default;
};

TEST(MaxHeapTest, WorksWithCustomTotallyOrderedType)
{
    MaxHeap<Job> heap({Job{5, 100}, Job{1, 200}, Job{3, 300}, Job{3, 350}});

    EXPECT_EQ(heap.remove(), (Job{5, 100}));
    EXPECT_EQ(heap.remove(), (Job{3, 350}));
    EXPECT_EQ(heap.remove(), (Job{3, 300}));
    EXPECT_EQ(heap.remove(), (Job{1, 200}));
}
