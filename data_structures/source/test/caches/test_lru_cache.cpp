//
// Created by andreas on 01.01.24.
//
#include "gtest/gtest.h"
#include "caches/lru_cache.h"


TEST(TestLRUCache, test_constructor_capacity)
{
	LRUCache<std::string, int> cache(1);
	cache.put("1", 1);
	EXPECT_EQ(cache.get("1"), 1);
	cache.put("2", 2);
	EXPECT_EQ(cache.get("1"), std::nullopt);
	EXPECT_EQ(cache.get("2"), 2);
}