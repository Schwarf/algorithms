//
// Created by andreas on 02.01.24.
//
#include "gtest/gtest.h"
#include "caches/lfu_cache.h"


TEST(TestLFUCache, test_constructor_capacity)
{
	LFUCache<std::string, int> cache(1);
	cache.put("1", 1);
	EXPECT_EQ(cache.get("1").value(), 1);
	cache.put("2", 2);
	EXPECT_EQ(cache.get("1"), std::nullopt);
	EXPECT_EQ(cache.get("2").value(), 2);
}

TEST(TestLFUCache, test_eviction_policy)
{
	LFUCache<int, int> cache(2);
	cache.put(1, 10);
	cache.put(2, 20);
	EXPECT_EQ(cache.get(1).value(), 10);
	cache.put(3, 30); // Element with key 2 should be evicted
	EXPECT_EQ(cache.get(1).value(), 10);
	EXPECT_EQ(cache.get(2), std::nullopt);
	EXPECT_EQ(cache.get(3), 30);
}

