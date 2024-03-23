//
// Created by andreas on 23.06.23.
//
#include "gtest/gtest.h"
#include "dictionaries/ordered_dictionary.h"

struct MoveOnlyType
{
	MoveOnlyType(int val)
		: value(val)
	{}
	MoveOnlyType(const MoveOnlyType &rhs) = delete;
	MoveOnlyType &operator=(const MoveOnlyType &rhs) = delete;
	MoveOnlyType(MoveOnlyType &&rhs)
		: value(rhs.value)
	{
		rhs.value = 0;
	}
	MoveOnlyType &operator=(MoveOnlyType &&rhs)
	{
		if (this != &rhs) {
			value = rhs.value;
			rhs.value = 0;
		}
		return *this;
	};

	int value{};
};

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

TEST(TestOrderedDictionary, insert_fill_and_get_with_rvalues)
{
	auto dictionary = OrderedDictionary<unsigned int, std::optional<unsigned int>>();
	constexpr int size{8};
	for (int i{}; i < size; ++i) {
		dictionary.insert(static_cast<unsigned int>(i), std::optional{static_cast<unsigned int>(i)});
	}
	EXPECT_EQ(size, dictionary.size());
	for (int i{}; i < size; ++i) {
		EXPECT_EQ(dictionary.get(static_cast<unsigned int>(i)), static_cast<unsigned int>(i));
	}
}

TEST(TestOrderedDictionary, insert_fill_and_get_with_MoveOnly)
{
	auto dictionary = OrderedDictionary<int, std::optional<MoveOnlyType>>();
	constexpr int size{4};

	for (int i{}; i < size; ++i) {
		auto move_only = MoveOnlyType(i);
		std::optional<MoveOnlyType> opt_value;
		opt_value = std::move(move_only);
		dictionary.insert(i, std::move(opt_value));
	}
	EXPECT_EQ(size, dictionary.size());
	for (int i{}; i < size; ++i) {
		auto move_only = MoveOnlyType(i);
		std::optional<MoveOnlyType> opt_value;
		opt_value = std::move(move_only);
		EXPECT_EQ(dictionary.get(i)->value, i);
	}
}
