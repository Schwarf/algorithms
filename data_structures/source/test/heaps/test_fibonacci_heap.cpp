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
    EXPECT_TRUE(heap.check_heap_property());
}


TEST(TestFibonacciHeap, heap_property) {
    constexpr double value1{10.0};
    constexpr double value2{20.0};
    constexpr double value3{30.0};
    constexpr double value4{40.0};
    constexpr double value5{50.0};
    constexpr int key1{1};
    constexpr int key2{2};
    constexpr int key3{3};
    constexpr int key4{4};
    constexpr int key5{5};
    auto heap = FibonacciHeap<int, double>();
    heap.insert(key3, value3);
    heap.insert(key2, value2);
    heap.insert(key5, value5);
    heap.insert(key1, value1);
    heap.insert(key4, value4);
    EXPECT_TRUE(heap.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(value1, heap.get_min());
}

TEST(TestFibonacciHeap, merge) {
    constexpr double value1{10.0};
    constexpr double value2{20.0};
    constexpr double value3{30.0};
    constexpr double value4{40.0};
    constexpr double value5{50.0};
    constexpr int key1{1};
    constexpr int key2{2};
    constexpr int key3{3};
    constexpr int key4{4};
    constexpr int key5{5};
    auto heap1 = FibonacciHeap<int, double>();
    auto heap2 = FibonacciHeap<int, double>();
    heap1.insert(key3, value3);
    heap2.insert(key2, value2);
    heap1.insert(key5, value5);
    heap2.insert(key1, value1);
    heap1.insert(key4, value4);
    EXPECT_TRUE(heap1.check_heap_property()) << "Heap property should be intact.";
    EXPECT_TRUE(heap2.check_heap_property()) << "Heap property should be intact.";
    EXPECT_EQ(value3, heap1.get_min());
    EXPECT_EQ(value1, heap2.get_min());
    heap1.merge(heap2);
    EXPECT_TRUE(heap1.check_heap_property());
    EXPECT_EQ(heap1.get_min(), value1);
}
