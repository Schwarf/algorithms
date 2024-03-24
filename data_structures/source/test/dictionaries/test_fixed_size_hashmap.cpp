//
// Created by andreas on 24.03.24.
//

#ifndef TEST_FIXED_SIZE_HASHMAP_H
#define TEST_FIXED_SIZE_HASHMAP_H
#include "dictionaries/fixed_size_hashmap.h"
#include "gtest/gtest.h"

TEST(TestFixedSizeHashMap, insert)
{
	auto map = FixedSizeHashmap<int, int, 2>();
	map.insert(1, 1);
	map.insert(2, 2);
	map.insert(3, 3);
}

#endif //TEST_FIXED_SIZE_HASHMAP_H
