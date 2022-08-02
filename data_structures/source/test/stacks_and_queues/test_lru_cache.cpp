//
// Created by andreas on 02.08.22.
//
#include "./../../stacks_and_queues/lru_cache.h"
#include "gtest/gtest.h"

TEST(test_lru_cache, test_lru_cache)
{
	auto cache = LRUCache<int, int>(3);
	cache.put(1,1);
	cache.put(2,2);
	cache.put(3,3);
	EXPECT_EQ(cache.get(1), 1);
	EXPECT_THROW(cache.get(4), std::exception);
}