//
// Created by andreas on 01.01.24.
//
#include "gtest/gtest.h"
#include "caches/lru_cache.h"

void createCacheWithNegativeCapacity() {
    LRUCache<std::string, int> cache(-1);
}
TEST(TestLRUCache, test_throws)
{
    EXPECT_THROW( createCacheWithNegativeCapacity() , std::invalid_argument);
}

TEST(TestLRUCache, test_eviction_policy1)
{
    LRUCache<std::string, int> cache(1);
    cache.put("1", 1);
    EXPECT_EQ(cache.get("1").value(), 1);
    cache.put("2", 2);
    EXPECT_EQ(cache.get("1"), std::nullopt);
    EXPECT_EQ(cache.get("2").value(), 2);
}

TEST(TestLRUCache, test_eviction_policy2)
{
    constexpr int capacity{5};
    LRUCache<int, int> cache(capacity);
    constexpr int value_conversion_factor{100};
    std::vector<int> keys1{1, 2, 3, 4, 5};
    for (const auto& key : keys1)
    {
        cache.put(key, key * value_conversion_factor);
    }
    std::vector<int> getKeys{1, 1, 2, 3, 1, 2, 4, 5};
    for (const auto& key : getKeys)
    {
        EXPECT_EQ(cache.get(key), key * value_conversion_factor);
    }
    std::vector<int> keys2{6, 7, 8, 9, 10};
    cache.put(keys2[0], keys2[0] * value_conversion_factor);
    EXPECT_FALSE(cache.get(3).has_value());
    cache.put(keys2[1], keys2[1] * value_conversion_factor);
    EXPECT_FALSE(cache.get(1).has_value());
    cache.put(keys2[2], keys2[2] * value_conversion_factor);
    EXPECT_FALSE(cache.get(2).has_value());
    cache.put(keys2[3], keys2[3] * value_conversion_factor);
    EXPECT_FALSE(cache.get(4).has_value());
    cache.put(keys2[4], keys2[4] * value_conversion_factor);
    EXPECT_FALSE(cache.get(5).has_value());
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
