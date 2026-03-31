//
// Created by andreas on 31.03.26.
//

#include "deques/double_ended_queue.h"
#include <gtest/gtest.h>

TEST(DequeTest, EmptyDeque) {
  Deque dq;
  EXPECT_TRUE(dq.isEmpty());
  EXPECT_EQ(dq.pop(), -1);
  EXPECT_EQ(dq.popleft(), -1);
}

TEST(DequeTest, SingleElementAppendAndPop) {
  Deque dq;
  dq.append(42);

  EXPECT_FALSE(dq.isEmpty());
  EXPECT_EQ(dq.pop(), 42);
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, SingleElementAppendLeftAndPopLeft) {
  Deque dq;
  dq.appendLeft(42);

  EXPECT_FALSE(dq.isEmpty());
  EXPECT_EQ(dq.popleft(), 42);
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, AppendThenPopLeftPreservesOrder) {
  Deque dq;
  dq.append(1);
  dq.append(2);
  dq.append(3);

  EXPECT_EQ(dq.popleft(), 1);
  EXPECT_EQ(dq.popleft(), 2);
  EXPECT_EQ(dq.popleft(), 3);
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, AppendThenPopPreservesReverseOrder) {
  Deque dq;
  dq.append(1);
  dq.append(2);
  dq.append(3);

  EXPECT_EQ(dq.pop(), 3);
  EXPECT_EQ(dq.pop(), 2);
  EXPECT_EQ(dq.pop(), 1);
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, AppendLeftChangesFrontOrder) {
  Deque dq;
  dq.appendLeft(1);
  dq.appendLeft(2);
  dq.appendLeft(3);

  EXPECT_EQ(dq.popleft(), 3);
  EXPECT_EQ(dq.popleft(), 2);
  EXPECT_EQ(dq.popleft(), 1);
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, MixedOperationsWork) {
  Deque dq;
  dq.append(2);     // [2]
  dq.appendLeft(1); // [1,2]
  dq.append(3);     // [1,2,3]

  EXPECT_EQ(dq.popleft(), 1); // [2,3]
  EXPECT_EQ(dq.pop(), 3);     // [2]
  EXPECT_EQ(dq.pop(), 2);     // []
  EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, CanBeReusedAfterBecomingEmpty) {
  Deque dq;
  dq.append(1);
  dq.append(2);
  EXPECT_EQ(dq.pop(), 2);
  EXPECT_EQ(dq.pop(), 1);
  EXPECT_TRUE(dq.isEmpty());

  dq.appendLeft(3);
  EXPECT_EQ(dq.popleft(), 3);
  EXPECT_TRUE(dq.isEmpty());
}