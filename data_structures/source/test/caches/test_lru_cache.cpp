//
// Created by andreas on 01.01.24.
//
#include "gtest/gtest.h"
#include "caches/lru_cache.h"


TEST(TestLRUCache, test_constructor_capacity)
{
	LRUCache<std::string, int> cache(1);
	cache.put("1", 1);
	EXPECT_EQ(cache.get("1").value(), 1);
	cache.put("2", 2);
	EXPECT_EQ(cache.get("1"), std::nullopt);
	EXPECT_EQ(cache.get("2").value(), 2);
}

TEST(TestLRUCache, test_put)
{
	LRUCache<int, int> cache(3);
	cache.put(1, -1);
	cache.put(2, -2);
	cache.put(3, -3);
	auto return_value = cache.get(1);
	EXPECT_TRUE(return_value.has_value());
	EXPECT_EQ(return_value.value(), -1);
	return_value = cache.get(2);
	EXPECT_TRUE(return_value.has_value());
	EXPECT_EQ(return_value.value(), -2);
	return_value = cache.get(3);
	EXPECT_TRUE(return_value.has_value());
	EXPECT_EQ(return_value.value(), -3);
}


TEST(TestLRUCache, test_size)
{
	LRUCache<int, int> cache(5);
	EXPECT_EQ(cache.size(), 0);
	cache.put(1, -1);
	cache.put(2, -2);
	cache.put(3, -3);
	EXPECT_EQ(cache.size(), 3);
	cache.put(4, -1);
	cache.put(5, -2);
	cache.put(6, -3);
	EXPECT_EQ(cache.size(), 5);
	EXPECT_EQ(cache.get(1), std::nullopt);
}

TEST(TestLRUCache, test_get)
{
	LRUCache<int, int> cache(3);
	cache.put(1, -1);
	auto return_value = cache.get(1);
	EXPECT_TRUE(return_value.has_value());
	EXPECT_EQ(return_value.value(), -1);
	cache.put(1, 1);
	return_value = cache.get(1);
	EXPECT_TRUE(return_value.has_value());
	EXPECT_EQ(return_value.value(), 1);
}