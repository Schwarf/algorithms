//
// Created by andreas on 24.03.24.
//

#ifndef TEST_FIXED_SIZE_HASHMAP_H
#define TEST_FIXED_SIZE_HASHMAP_H
#include "dictionaries/fixed_size_hashmap.h"
#include "gtest/gtest.h"

TEST(TestFixedSizeHashMap, insert_throws)
{
    auto map = FixedSizeHashmap<int, int, 2>();
    map.insert(1, 1);
    map.insert(2, 2);
    EXPECT_THROW(map.insert(3, 3), std::overflow_error);
}

TEST(TestFixedSizeHashMap, get_throws)
{
    auto map = FixedSizeHashmap<int, int, 2>();
    map.insert(1, 1);
    EXPECT_THROW(map.get(3), std::out_of_range);
    EXPECT_THROW(map.get(2), std::out_of_range);
}


TEST(TestFixedSizeHashMap, insert_get)
{
    auto map = FixedSizeHashmap<int, int, 2>();
    map.insert(1, 1);
    EXPECT_EQ(map.get(1), 1);
    map.insert(2, 2);
    EXPECT_EQ(map.get(2), 2);
    map.insert(2, 3);
    EXPECT_EQ(map.get(2), 3);
    map.insert(1, 4);
    EXPECT_EQ(map.get(1), 4);
}

#endif //TEST_FIXED_SIZE_HASHMAP_H
