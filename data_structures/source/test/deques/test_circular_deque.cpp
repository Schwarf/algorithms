//
// Created by andreas on 29.09.24.
//
#include <deque>
#include "gtest/gtest.h"
#include "deques/circular_deque.h"


TEST(TestCircularDeque, InsertFront)
{
    auto deque = CircularDeque<int>(3);
    EXPECT_TRUE(deque.insert_front(1));
    EXPECT_TRUE(deque.insert_front(2));
    EXPECT_TRUE(deque.insert_front(3));
    EXPECT_FALSE(deque.insert_front(4));
}

TEST(TestCircularDeque, InsertBack)
{
    auto deque = CircularDeque<int>(3);
    EXPECT_TRUE(deque.insert_back(1));
    EXPECT_TRUE(deque.insert_back(2));
    EXPECT_TRUE(deque.insert_back(3));
    EXPECT_FALSE(deque.insert_back(4));
}

TEST(TestCircularDeque, DeleteFront)
{
    auto deque = CircularDeque<int>(3);
    EXPECT_TRUE(deque.insert_front(1));
    EXPECT_TRUE(deque.insert_front(2));
    EXPECT_TRUE(deque.insert_front(3));
    EXPECT_FALSE(deque.insert_front(4));
    EXPECT_TRUE(deque.delete_front());
    EXPECT_TRUE(deque.delete_front());
    EXPECT_TRUE(deque.delete_front());
    EXPECT_FALSE(deque.delete_front());
}


TEST(TestCircularDeque, DeleteBack)
{
    auto deque = CircularDeque<int>(3);
    EXPECT_TRUE(deque.insert_back(1));
    EXPECT_TRUE(deque.insert_back(2));
    EXPECT_TRUE(deque.insert_back(3));
    EXPECT_FALSE(deque.insert_back(4));
    EXPECT_TRUE(deque.delete_back());
    EXPECT_TRUE(deque.delete_back());
    EXPECT_TRUE(deque.delete_back());
    EXPECT_FALSE(deque.delete_back());
}

TEST(TestCircularDeque, GetFront)
{
    auto deque = CircularDeque<uint8_t>(5);
    constexpr uint8_t value1{1};
    constexpr uint8_t value2{2};
    constexpr uint8_t value3{3};
    constexpr uint8_t value4{4};

    EXPECT_FALSE(deque.get_front().has_value());

    EXPECT_TRUE(deque.insert_front(value1));
    EXPECT_TRUE(deque.get_front().has_value());
    EXPECT_EQ(deque.get_front().value(), value1);

    EXPECT_TRUE(deque.insert_front(value2));
    EXPECT_TRUE(deque.get_front().has_value());
    EXPECT_EQ(deque.get_front().value(), value2);

    EXPECT_TRUE(deque.insert_front(value3));
    EXPECT_TRUE(deque.get_front().has_value());
    EXPECT_EQ(deque.get_front().value(), value3);

    EXPECT_TRUE(deque.insert_front(value4));
    EXPECT_TRUE(deque.get_front().has_value());
    EXPECT_EQ(deque.get_front().value(), value4);
}

TEST(TestCircularDeque, GetBack)
{
    auto deque = CircularDeque<uint8_t>(5);
    constexpr uint8_t value1{1};
    constexpr uint8_t value2{2};
    constexpr uint8_t value3{3};
    constexpr uint8_t value4{4};

    EXPECT_FALSE(deque.get_back().has_value());

    EXPECT_TRUE(deque.insert_back(value1));
    EXPECT_TRUE(deque.get_back().has_value());
    EXPECT_EQ(deque.get_back().value(), value1);

    EXPECT_TRUE(deque.insert_back(value2));
    EXPECT_TRUE(deque.get_back().has_value());
    EXPECT_EQ(deque.get_back().value(), value2);

    EXPECT_TRUE(deque.insert_back(value3));
    EXPECT_TRUE(deque.get_back().has_value());
    EXPECT_EQ(deque.get_back().value(), value3);

    EXPECT_TRUE(deque.insert_back(value4));
    EXPECT_TRUE(deque.get_back().has_value());
    EXPECT_EQ(deque.get_back().value(), value4);
}


TEST(TestCircularDeque, IsEmpty)
{
    auto deque = CircularDeque<uint8_t>(2);
    EXPECT_TRUE(deque.is_empty());
    deque.insert_front(1);
    EXPECT_FALSE(deque.is_empty());
    deque.delete_front();
    EXPECT_TRUE(deque.is_empty());
}

TEST(TestCircularDeque, IsFull)
{
    auto deque = CircularDeque<uint8_t>(2);
    EXPECT_FALSE(deque.is_full());
    deque.insert_front(1);
    EXPECT_FALSE(deque.is_full());
    deque.insert_front(2);
    EXPECT_TRUE(deque.is_full());
    deque.delete_front();
    EXPECT_FALSE(deque.is_full());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TestCircularDequeArray, InsertFront)
{
    auto deque = CircularDequeArray<int>(3);
    EXPECT_TRUE(deque.insert_front(1));
    EXPECT_TRUE(deque.insert_front(2));
    EXPECT_TRUE(deque.insert_front(3));
    EXPECT_FALSE(deque.insert_front(4));
}

TEST(TestCircularDequeArray, InsertBack)
{
    auto deque = CircularDequeArray<int>(3);
    EXPECT_TRUE(deque.insert_back(1));
    EXPECT_TRUE(deque.insert_back(2));
    EXPECT_TRUE(deque.insert_back(3));
    EXPECT_FALSE(deque.insert_back(4));
}

TEST(TestCircularDequeArray, DeleteFront)
{
    auto deque = CircularDequeArray<int>(3);
    EXPECT_TRUE(deque.insert_front(1));
    EXPECT_TRUE(deque.insert_front(2));
    EXPECT_TRUE(deque.insert_front(3));
    EXPECT_FALSE(deque.insert_front(4));
    EXPECT_TRUE(deque.delete_front());
    EXPECT_TRUE(deque.delete_front());
    EXPECT_TRUE(deque.delete_front());
    EXPECT_FALSE(deque.delete_front());
}


TEST(TestCircularDequeArray, DeleteBack)
{
    auto deque = CircularDequeArray<int>(3);
    EXPECT_TRUE(deque.insert_back(1));
    EXPECT_TRUE(deque.insert_back(2));
    EXPECT_TRUE(deque.insert_back(3));
    EXPECT_FALSE(deque.insert_back(4));
    EXPECT_TRUE(deque.delete_back());
    EXPECT_TRUE(deque.delete_back());
    EXPECT_TRUE(deque.delete_back());
    EXPECT_FALSE(deque.delete_back());
}

TEST(TestCircularDequeArray, GetFront)
{
    auto deque = CircularDequeArray<uint8_t>(5);
    constexpr uint8_t value1{1};
    constexpr uint8_t value2{2};
    constexpr uint8_t value3{3};
    constexpr uint8_t value4{4};

    EXPECT_FALSE(deque.get_front().has_value());

    EXPECT_TRUE(deque.insert_front(value1));
    EXPECT_TRUE(deque.get_front().has_value());
    EXPECT_EQ(deque.get_front().value(), value1);

    EXPECT_TRUE(deque.insert_front(value2));
    EXPECT_TRUE(deque.get_front().has_value());
    EXPECT_EQ(deque.get_front().value(), value2);

    EXPECT_TRUE(deque.insert_front(value3));
    EXPECT_TRUE(deque.get_front().has_value());
    EXPECT_EQ(deque.get_front().value(), value3);

    EXPECT_TRUE(deque.insert_front(value4));
    EXPECT_TRUE(deque.get_front().has_value());
    EXPECT_EQ(deque.get_front().value(), value4);
}

TEST(TestCircularDequeArray, GetBack)
{
    auto deque = CircularDequeArray<uint8_t>(5);
    constexpr uint8_t value1{1};
    constexpr uint8_t value2{2};
    constexpr uint8_t value3{3};
    constexpr uint8_t value4{4};

    EXPECT_FALSE(deque.get_back().has_value());

    EXPECT_TRUE(deque.insert_back(value1));
    EXPECT_TRUE(deque.get_back().has_value());
    EXPECT_EQ(deque.get_back().value(), value1);

    EXPECT_TRUE(deque.insert_back(value2));
    EXPECT_TRUE(deque.get_back().has_value());
    EXPECT_EQ(deque.get_back().value(), value2);

    EXPECT_TRUE(deque.insert_back(value3));
    EXPECT_TRUE(deque.get_back().has_value());
    EXPECT_EQ(deque.get_back().value(), value3);

    EXPECT_TRUE(deque.insert_back(value4));
    EXPECT_TRUE(deque.get_back().has_value());
    EXPECT_EQ(deque.get_back().value(), value4);
}


TEST(TestCircularDequeArray, IsEmpty)
{
    auto deque = CircularDequeArray<uint8_t>(2);
    EXPECT_TRUE(deque.is_empty());
    deque.insert_front(1);
    EXPECT_FALSE(deque.is_empty());
    deque.delete_front();
    EXPECT_TRUE(deque.is_empty());
}

TEST(TestCircularDequeArray, IsFull)
{
    auto deque = CircularDequeArray<uint8_t>(2);
    EXPECT_FALSE(deque.is_full());
    deque.insert_front(1);
    EXPECT_FALSE(deque.is_full());
    deque.insert_front(2);
    EXPECT_TRUE(deque.is_full());
    deque.delete_front();
    EXPECT_FALSE(deque.is_full());
}
