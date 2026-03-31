//
// Created by andreas on 31.03.26.
//

#include "deques/double_ended_queue.h"
#include <gtest/gtest.h>

TEST(DequeTest, EmptyDeque) {
  Deque<int> dq;
  EXPECT_TRUE(dq.isEmpty());
  EXPECT_EQ(dq.pop(), std::nullopt);
  EXPECT_EQ(dq.popleft(), std::nullopt);
}

TEST(DequeTest, SingleElementAppendAndPop) {
  Deque<int> dq;
  dq.append(42);

  EXPECT_FALSE(dq.isEmpty());
  EXPECT_EQ(dq.pop(), 42);
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, SingleElementAppendLeftAndPopLeft) {
  Deque<int> dq;
  dq.appendLeft(42);

  EXPECT_FALSE(dq.isEmpty());
  EXPECT_EQ(dq.popleft(), 42);
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, AppendThenPopLeftPreservesOrder) {
  Deque<short> dq;
  dq.append(1);
  dq.append(2);
  dq.append(3);

  EXPECT_EQ(dq.popleft(), 1);
  EXPECT_EQ(dq.popleft(), 2);
  EXPECT_EQ(dq.popleft(), 3);
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, AppendThenPopPreservesReverseOrder) {
  Deque<int64_t> dq;
  dq.append(1);
  dq.append(2);
  dq.append(3);

  EXPECT_EQ(dq.pop(), 3);
  EXPECT_EQ(dq.pop(), 2);
  EXPECT_EQ(dq.pop(), 1);
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, AppendLeftChangesFrontOrder) {
  Deque<float> dq;
  dq.appendLeft(1.F);
  dq.appendLeft(2.F);
  dq.appendLeft(3.F);

  EXPECT_EQ(dq.popleft(), 3.F);
  EXPECT_EQ(dq.popleft(), 2.F);
  EXPECT_EQ(dq.popleft(), 1.F);
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, MixedOperationsWork) {
  Deque<int> dq;
  dq.append(2);     // [2]
  dq.appendLeft(1); // [1,2]
  dq.append(3);     // [1,2,3]

  EXPECT_EQ(dq.popleft(), 1); // [2,3]
  EXPECT_EQ(dq.pop(), 3);     // [2]
  EXPECT_EQ(dq.pop(), 2);     // []
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, CanBeReusedAfterBecomingEmpty) {
  Deque<int> dq;
  dq.append(1);
  dq.append(2);
  EXPECT_EQ(dq.pop(), 2);
  EXPECT_EQ(dq.pop(), 1);
  EXPECT_TRUE(dq.isEmpty());

  dq.appendLeft(3);
  EXPECT_EQ(dq.popleft(), 3);
  EXPECT_TRUE(dq.isEmpty());
}