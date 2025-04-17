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

TEST(TestCircularDeque, MixedOperations)
{
    CircularDeque<int> deque(4);
    EXPECT_TRUE(deque.is_empty());
    EXPECT_FALSE(deque.is_full());

    // Insert elements at front and back
    EXPECT_TRUE(deque.insert_back(1));  // deque: [1]
    EXPECT_TRUE(deque.insert_front(2)); // deque: [2, 1]
    EXPECT_TRUE(deque.insert_back(3));  // deque: [2, 1, 3]
    EXPECT_TRUE(deque.insert_front(4)); // deque: [4, 2, 1, 3]
    EXPECT_FALSE(deque.insert_back(5)); // should fail, full

    EXPECT_TRUE(deque.is_full());
    EXPECT_FALSE(deque.is_empty());

    // Check front and back
    auto front = deque.get_front();
    auto back = deque.get_back();
    EXPECT_TRUE(front.has_value());
    EXPECT_EQ(front.value(), 4);
    EXPECT_TRUE(back.has_value());
    EXPECT_EQ(back.value(), 3);

    // Delete from both ends
    EXPECT_TRUE(deque.delete_back());  // deque: [4, 2, 1]
    EXPECT_TRUE(deque.delete_front()); // deque: [2, 1]
    EXPECT_FALSE(deque.is_full());
    EXPECT_FALSE(deque.is_empty());

    // Check front and back again
    front = deque.get_front();
    back = deque.get_back();
    EXPECT_TRUE(front.has_value());
    EXPECT_EQ(front.value(), 2);
    EXPECT_TRUE(back.has_value());
    EXPECT_EQ(back.value(), 1);

    // Insert again after deletions
    EXPECT_TRUE(deque.insert_back(5));  // deque: [2, 1, 5]
    EXPECT_TRUE(deque.insert_front(6)); // deque: [6, 2, 1, 5]
    EXPECT_FALSE(deque.insert_back(7)); // full

    // Final structure check
    EXPECT_TRUE(deque.is_full());
    EXPECT_EQ(deque.get_front().value(), 6);
    EXPECT_EQ(deque.get_back().value(), 5);

    // Clear all
    EXPECT_TRUE(deque.delete_front()); // [2, 1, 5]
    EXPECT_TRUE(deque.delete_front()); // [1, 5]
    EXPECT_TRUE(deque.delete_back());  // [1]
    EXPECT_TRUE(deque.delete_back());  // []
    EXPECT_FALSE(deque.delete_back()); // nothing to delete

    EXPECT_TRUE(deque.is_empty());
    EXPECT_FALSE(deque.get_front().has_value());
    EXPECT_FALSE(deque.get_back().has_value());
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
