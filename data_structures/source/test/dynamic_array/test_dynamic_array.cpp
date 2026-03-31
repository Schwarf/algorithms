//
// Created by andreas on 31.03.26.
//
#include "dynamic_array/dynamic_array.h"
#include "gtest/gtest.h"

//
// Created by andreas on 31.03.26.
//
#include "dynamic_array/dynamic_array.h"
#include "gtest/gtest.h"

TEST(DynamicArrayTest, ConstructorRejectsNonPositiveCapacity) {
    EXPECT_THROW(DynamicArray<int>(0), std::invalid_argument);
    EXPECT_THROW(DynamicArray<int>(-1), std::invalid_argument);
}

TEST(DynamicArrayTest, NewArrayIsEmptyAndHasCapacity) {
    DynamicArray<int> arr(4);

    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_EQ(arr.getCapacity(), 4);
}

TEST(DynamicArrayTest, PushBackAndGetWorkForInt) {
    DynamicArray<int> arr(3);

    arr.pushBack(10);
    arr.pushBack(20);
    arr.pushBack(30);

    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr.getCapacity(), 3);
    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(1), 20);
    EXPECT_EQ(arr.get(2), 30);
}

TEST(DynamicArrayTest, SetUpdatesElementForUnsignedInt) {
    DynamicArray<unsigned int> arr(2);

    arr.pushBack(10u);
    arr.pushBack(20u);
    arr.set(1, 99u);

    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr.get(0), 10u);
    EXPECT_EQ(arr.get(1), 99u);
}

TEST(DynamicArrayTest, PushBackResizesWhenFullForFloat) {
    DynamicArray<float> arr(2);

    arr.pushBack(1.5f);
    arr.pushBack(2.5f);
    arr.pushBack(3.5f);

    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr.getCapacity(), 4);
    EXPECT_FLOAT_EQ(arr.get(0), 1.5f);
    EXPECT_FLOAT_EQ(arr.get(1), 2.5f);
    EXPECT_FLOAT_EQ(arr.get(2), 3.5f);
}

TEST(DynamicArrayTest, PopBackReturnsLastElementAndReducesSize) {
    DynamicArray<int> arr(2);

    arr.pushBack(5);
    arr.pushBack(7);

    EXPECT_EQ(arr.popBack(), 7);
    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr.get(0), 5);

    EXPECT_EQ(arr.popBack(), 5);
    EXPECT_EQ(arr.getSize(), 0);
}

TEST(DynamicArrayTest, GetThrowsForInvalidIndex) {
    DynamicArray<int> arr(2);
    arr.pushBack(42);

    EXPECT_THROW(arr.get(-1), std::out_of_range);
    EXPECT_THROW(arr.get(1), std::out_of_range);
}

TEST(DynamicArrayTest, SetThrowsForInvalidIndex) {
    DynamicArray<int> arr(2);
    arr.pushBack(42);

    EXPECT_THROW(arr.set(-1, 5), std::out_of_range);
    EXPECT_THROW(arr.set(1, 5), std::out_of_range);
}

TEST(DynamicArrayTest, PopBackThrowsWhenEmpty) {
    DynamicArray<int> arr(2);

    EXPECT_THROW(arr.popBack(), std::out_of_range);
}