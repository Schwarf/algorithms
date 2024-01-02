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

TEST(TestLFUCache, test_eviction_policy1)
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


TEST(TestLFUCache, test_eviction_policy2)
{
	LFUCache<int, int> cache(5);
	constexpr int value_conversion_factor{100};
	std::vector<int> keys1{1, 2, 3, 4, 5};
	for (const auto &key: keys1) {
		cache.put(key, key * value_conversion_factor);
	}
	std::vector<int> getKeys{1, 1, 2, 3, 1, 2, 4, 5};
	for (const auto &key: getKeys) {
		EXPECT_EQ(cache.get(key), key * value_conversion_factor);
	}
	std::vector<int> keys2{6, 7, 8, 9, 10};
	cache.put(keys2[0], keys2[0] * value_conversion_factor);
	EXPECT_FALSE(cache.get(keys1[0]).has_value());
	cache.put(keys2[1], keys2[1] * value_conversion_factor);
	EXPECT_FALSE(cache.get(keys2[0]).has_value());
	cache.put(keys2[2], keys2[2] * value_conversion_factor);
	EXPECT_FALSE(cache.get(keys2[1]).has_value());
	cache.put(keys2[3], keys2[3] * value_conversion_factor);
	EXPECT_FALSE(cache.get(keys2[2]).has_value());
	cache.put(keys2[4], keys2[4] * value_conversion_factor);
	EXPECT_FALSE(cache.get(keys2[3]).has_value());
}

TEST(TestLFUCache, test_eviction_policy3)
{
	LFUCache<int, int> cache(5);
	constexpr int value_conversion_factor{100};
	std::vector<int> keys1{1, 2, 3, 4, 5};
	for (const auto &key: keys1) {
		cache.put(key, key * value_conversion_factor);
	}
	std::vector<int> getKeys{1, 1, 2, 3, 1, 2, 4, 5};
	for (const auto &key: getKeys) {
		EXPECT_EQ(cache.get(key), key * value_conversion_factor);
	}
	std::vector<int> keys2{6, 7, 8, 9, 10};
	cache.put(keys2[0], keys2[0] * value_conversion_factor);
	EXPECT_FALSE(cache.get(keys1[2]).has_value());

	EXPECT_EQ(cache.get(keys2[0]), keys2[0] * value_conversion_factor); // get first element of keys2
	cache.put(keys2[1], keys2[1] * value_conversion_factor);// evicts keys1[3] = 4 and puts keys2[1] = 7
	EXPECT_FALSE(cache.get(keys1[3]).has_value());

	cache.put(keys2[2], keys2[2] * value_conversion_factor); // put keys2[2] = 8 and evicts keys2[1] = 7
	EXPECT_FALSE(cache.get(keys2[1]).has_value());
	EXPECT_EQ(cache.get(keys2[2]), keys2[2] * value_conversion_factor); // add frequency to keys2[2] = 8

	cache.put(keys2[3], keys2[3] * value_conversion_factor); // put keys2[3] = 9 and evicts keys1[4] = 5
	EXPECT_FALSE(cache.get(keys1[4]).has_value());
	cache.get(keys2[3]);
	cache.get(keys2[3]);
	cache.get(keys2[2]);
	cache.get(keys2[2]);
	cache.get(keys2[0]);

	cache.put(keys2[4], keys2[4] * value_conversion_factor); // put keys2[4] = 10 and evicts keys1[1] = 2
	EXPECT_FALSE(cache.get(keys1[1]).has_value());

}

