//
// Created by andreas on 23.06.23.
//
#include "gtest/gtest.h"
#include "dictionaries/ordered_dictionary.h"

TEST(TestOrderedDictionary, insert_fill)
{
	auto keys = std::vector<char>{1, 2, 3, 4, 5, 6};
	auto values = std::vector<std::optional<int>>{1, 2, 3, 4, 5, 6};
	auto dictionary = OrderedDictionary<int, std::optional<int>>();
	EXPECT_NE(keys.size(), dictionary.size());
	for (int i{}; i < keys.size(); ++i) {
		dictionary.insert(keys[i], values[i]);
	}
	EXPECT_EQ(keys.size(), dictionary.size());
	EXPECT_EQ(values.size(), dictionary.size());
}


TEST(TestOrderedDictionary, get)
{
	auto keys = std::vector<char>{1, 2, 3, 4, 5, 6};
	auto values = std::vector<std::optional<int>>{1, 2, 3, 4, 5, 6};
	auto dictionary = OrderedDictionary<int, std::optional<int>>();
	for (int i{}; i < keys.size(); ++i) {
		EXPECT_FALSE(dictionary.get(keys[i]).has_value());
		dictionary.insert(keys[i], values[i]);
		EXPECT_TRUE(dictionary.get(keys[i]).has_value());
		EXPECT_EQ(dictionary.get(keys[i]).value(), values[i].value());
	}
}

TEST(TestOrderedDictionary, front)
{
	auto keys = std::vector<char>{1, 2, 3, 4, 5, 6};
	auto values = std::vector<std::optional<int>>{1, 2, 3, 4, 5, 6};
	auto dictionary = OrderedDictionary<int, std::optional<int>>();
	EXPECT_FALSE(dictionary.front().has_value());
	for (int i{}; i < keys.size(); ++i) {
		dictionary.insert(keys[i], values[i]);
		EXPECT_TRUE(dictionary.front().has_value());
		EXPECT_EQ(dictionary.front().value(), values[0].value());
		EXPECT_EQ(dictionary.size(), i + 1);
	}
}

TEST(TestOrderedDictionary, back)
{
	auto keys = std::vector<char>{1, 2, 3, 4, 5, 6};
	auto values = std::vector<std::optional<int>>{1, 2, 3, 4, 5, 6};
	auto dictionary = OrderedDictionary<int, std::optional<int>>();
	EXPECT_FALSE(dictionary.back().has_value());
	for (int i{}; i < keys.size(); ++i) {
		dictionary.insert(keys[i], values[i]);
		EXPECT_TRUE(dictionary.back().has_value());
		EXPECT_EQ(dictionary.back().value(), values[i].value());
		EXPECT_EQ(dictionary.size(), i + 1);
	}
}
