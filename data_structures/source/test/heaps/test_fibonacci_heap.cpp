//
// Created by andreas on 23.04.24.
//
#include "gtest/gtest.h"
#include "heaps/fibonacci_heap.h"

TEST(TestFibonacciHeap, insert) {
    constexpr double value1{1.0};
    constexpr double value2{2.0};
    constexpr double value3{3.0};

    constexpr int key1{1};
    constexpr int key2{2};
    constexpr int key3{3};

    auto heap = FibonacciHeap<int, double>();
    heap.insert(key1, value1);
    heap.insert(key2, value2);
    heap.insert(key3, value3);
    EXPECT_EQ(value1, heap.get_min());
}