//
// Created by andreas on 02.08.22.
//
#include "./../../stacks_and_queues/lru_cache.h"
#include "gtest/gtest.h"

TEST(test_lru_cache, test_lru_cache)
{
	auto cache = LRUCache<int, int>(3);
	cache.put(1, 1);
	cache.put(2, 2);
	cache.put(3, 3);
	EXPECT_EQ(cache.get(1), 1);
	EXPECT_THROW(cache.get(4), std::exception);
}

TEST(test_lru_cache, test_lru_cache_values)
{
	auto cache = LRUCache<int, int>(3);
	cache.put(1, 1);
	cache.put(2, 2);
	cache.put(3, 3);
	cache.put(4, 4);
	auto expected_content = std::vector<int>{4, 3, 2};
	auto content = cache.get_all_values();
	for (int i = 0; i < content.size(); ++i) {
		EXPECT_EQ(content[i], expected_content[i]);
	}
	expected_content = std::vector<int>{2, 4, 3};
	cache.get(2);
	content = cache.get_all_values();
	for (int i = 0; i < content.size(); ++i) {
		EXPECT_EQ(content[i], expected_content[i]);
	}

}