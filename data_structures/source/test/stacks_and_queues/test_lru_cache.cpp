//
// Created by andreas on 02.08.22.
//
#include "./../../stacks_and_queues/lru_cache.h"
#include "gtest/gtest.h"

TEST(test_lru_cache, test_lru_cache)
{
	auto cache = LRUCache<int, int>(3);
	cache.put(1, 1);
	EXPECT_EQ(cache.get_most_recent_value(), 1);
	cache.put(2, 2);
	EXPECT_EQ(cache.get_most_recent_value(), 2);
	cache.put(3, 3);
	EXPECT_EQ(cache.get_most_recent_value(), 3);
	EXPECT_EQ(cache.get(1), 1);
	EXPECT_THROW(cache.get(4), std::exception);
}

TEST(test_lru_cache, test_lru_cache_values)
{
	auto cache = LRUCache<int, int>(3);
	cache.put(1, 1);
	EXPECT_EQ(cache.get_most_recent_value(), 1);
	cache.put(2, 2);
	EXPECT_EQ(cache.get_most_recent_value(), 2);
	cache.put(3, 3);
	EXPECT_EQ(cache.get_most_recent_value(), 3);
	cache.put(4, 4);
	EXPECT_EQ(cache.get_most_recent_value(), 4);
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


TEST(test_lru_cache, test_lru_cache_keys)
{
	auto cache = LRUCache<int, int>(3);
	cache.put(1, 1);
	EXPECT_EQ(cache.get_most_recent_value(), 1);
	cache.put(2, 2);
	EXPECT_EQ(cache.get_most_recent_value(), 2);
	cache.put(3, 3);
	EXPECT_EQ(cache.get_most_recent_value(), 3);
	cache.put(4, 4);
	EXPECT_EQ(cache.get_most_recent_value(), 4);
	auto expected_content = std::vector<int>{4, 3, 2};
	auto content = cache.get_all_keys();
	for (int i = 0; i < content.size(); ++i) {
		EXPECT_EQ(content[i], expected_content[i]);
	}
	expected_content = std::vector<int>{2, 4, 3};
	cache.get(2);
	content = cache.get_all_keys();
	for (int i = 0; i < content.size(); ++i) {
		EXPECT_EQ(content[i], expected_content[i]);
	}
}

TEST(test_lru_cache, test_lru_cache_invalid_key)
{
	auto cache = LRUCache<int, int>(3);
	cache.put(1, 1);
	EXPECT_EQ(cache.get_most_recent_value(), 1);
	cache.put(2, 2);
	std::string message = "Element not in cache!";
	try {
		cache.get(3);
		FAIL() << "Expected std::out_of_range.";
	}
	catch (std::out_of_range const &err) {
		EXPECT_TRUE(err.what() == message);
	}
}
