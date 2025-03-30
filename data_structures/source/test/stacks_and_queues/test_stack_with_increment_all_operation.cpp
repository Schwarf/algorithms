#include <gtest/gtest.h>
#include "stacks_and_queues/stack_with_increment_all_operation.h"  // Assuming the IncrementStack class is defined here.

// Test fixture for handling setup and teardown for tests
template <typename T>
class IncrementStackTest : public ::testing::Test
{
protected:
    IncrementStack<T>* stack;

    void SetUp() override
    {
        // Initialize with a reasonable size for testing.
        stack = new IncrementStack<T>(5);
    }

    void TearDown() override
    {
        delete stack;
    }
};

using MyTypes = ::testing::Types<int, double>; // You can add more types to test.
TYPED_TEST_SUITE(IncrementStackTest, MyTypes);

// Test pushing and popping values.
TYPED_TEST(IncrementStackTest, PushAndPop)
{
    this->stack->push(1);
    this->stack->push(2);
    auto value = this->stack->pop();
    EXPECT_EQ(value, 2);

    value = this->stack->pop();
    EXPECT_EQ(value, 1);

    // Test popping from an empty stack
    value = this->stack->pop();
    EXPECT_EQ(value, std::nullopt);
}

// Test exceeding stack capacity.
TYPED_TEST(IncrementStackTest, ExceedCapacity)
{
    for (int i = 0; i < 6; ++i)
    {
        // push more elements than capacity
        this->stack->push(i);
    }
    int validPops = 0;
    while (this->stack->pop())
    {
        ++validPops;
    }
    EXPECT_EQ(validPops, 5); // Only 5 should have been stored.
}

// Test increment operation with various scenarios.
TYPED_TEST(IncrementStackTest, IncrementOperation)
{
    this->stack->push(1);
    this->stack->push(2);
    this->stack->push(3);

    // Increment the bottom 2 elements by 10
    this->stack->increment(10, 2);

    EXPECT_EQ(this->stack->pop(), 3);
    EXPECT_EQ(this->stack->pop(), 12); // 2 + 10
    EXPECT_EQ(this->stack->pop(), 11); // 1 + 10

    // Check pop on now empty stack
    EXPECT_EQ(this->stack->pop(), std::nullopt);
}

// Test increment edge cases
TYPED_TEST(IncrementStackTest, IncrementEdgeCases)
{
    // Increment an empty stack
    this->stack->increment(10, 1); // Should do nothing, safely.
    EXPECT_EQ(this->stack->pop(), std::nullopt);

    // Increment more elements than present
    this->stack->push(5);
    this->stack->increment(5, 3); // Increment more than size
    EXPECT_EQ(this->stack->pop(), 10); // Only the one element incremented

    // Fill the stack and increment all elements
    this->stack->push(1);
    this->stack->push(2);
    this->stack->push(3);
    this->stack->push(4);
    this->stack->increment(5, 5); // Increment more elements than stack holds
    EXPECT_EQ(this->stack->pop(), 9); // 4 + 5
    EXPECT_EQ(this->stack->pop(), 8); // 3 + 5
    EXPECT_EQ(this->stack->pop(), 7); // 2 + 5
    EXPECT_EQ(this->stack->pop(), 6); // 1 + 5
}
