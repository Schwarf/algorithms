//
// Created by andreas on 27.04.25.
//
#include <json.hpp>

#include "linked_lists/skip_lists/skip_list.h"
#include "gtest/gtest.h"

TEST(SkipListTest, SearchEmpty) {
    SkipList<int, std::string, 32> skip_list;
    std::string value;
    EXPECT_FALSE(skip_list.search(10, value));
    EXPECT_EQ(skip_list.get(10), std::nullopt);
}

TEST(SkipListTest, InsertAndSerach)
{
    SkipList<int, uint32_t, 32> skip_list;
    for (int i = 0; i < 30; i+=2)
    {
        skip_list.insert(i, i*10);
    }

    for (int i = 0 ; i < 30; ++i)
    {
        uint32_t value{};

        if (i & 1)
        {
            EXPECT_FALSE(skip_list.search(i, value));
        }
        else
        {
            EXPECT_TRUE(skip_list.search(i, value));
            EXPECT_EQ(value, i*10);
        }

    }
}

TEST(SkipListTest, UpdateExisting) {
    SkipList<int, std::string, 32> skip_list;

    skip_list.insert(2, "two");
    {
        auto optional_value = skip_list.get(2);
        EXPECT_TRUE(optional_value.has_value());
        EXPECT_EQ(optional_value.value(), "two");
    }

    skip_list.insert(2, "deux");
    {
        auto optional_value = skip_list.get(2);
        EXPECT_TRUE(optional_value.has_value());
        EXPECT_EQ(optional_value.value(), "deux");
    }
}

