//
// Created by andreas on 18.10.25.
//

// max_distinct_elements_test.cpp
#include "../max_number_of_diff_elements.h"
#include "gtest/gtest.h"

static int call_max_distinct_elements(std::initializer_list<int> il, int k) {
    std::vector<int> v(il);
    return max_distinct_elements(v, k);
}
// Forward-declare the function under test if it's not included via a header.
TEST(max_distinct_elementsTest, EmptyArray) {
    std::vector<int> v;
    EXPECT_EQ(max_distinct_elements(v, /*k=*/0), 0);
    EXPECT_EQ(max_distinct_elements(v, /*k=*/10), 0);
}

TEST(max_distinct_elementsTest, SingleElement) {
    EXPECT_EQ(call_max_distinct_elements({5}, 0), 1);
    EXPECT_EQ(call_max_distinct_elements({-7}, 100), 1);
}

TEST(max_distinct_elementsTest, AlreadyDistinct_kZero) {
    EXPECT_EQ(call_max_distinct_elements({1,2,3,4,5}, 0), 5);
    EXPECT_EQ(call_max_distinct_elements({-3,-2,-1,0,1}, 0), 5);
}

TEST(max_distinct_elementsTest, AllEqual_kZero) {
    EXPECT_EQ(call_max_distinct_elements({7,7,7,7}, 0), 1);
}

TEST(max_distinct_elementsTest, AllEqual_SmallK_LimitedByRangeCapacity) {
    // All intervals are [-1,1]; capacity is 3 integers {-1,0,1}.
    // With 5 numbers, the best we can do is 3 distinct.
    EXPECT_EQ(call_max_distinct_elements({0,0,0,0,0}, 1), 3);
}

TEST(max_distinct_elementsTest, AllEqual_LargeK_CanMakeAllDistinct) {
    // All intervals are [-2,2]; capacity is 5 integers {-2,-1,0,1,2}.
    // With 5 numbers, we can reach 5 distinct.
    EXPECT_EQ(call_max_distinct_elements({0,0,0,0,0}, 2), 5);
}

TEST(max_distinct_elementsTest, MixedDuplicates_kZero) {
    EXPECT_EQ(call_max_distinct_elements({1,1,2,2,3,3}, 0), 3);
}

TEST(max_distinct_elementsTest, BasicOverlapsEnableConsecutivePacking) {
    // Example akin to explanation: intervals chain to allow all distinct.
    EXPECT_EQ(call_max_distinct_elements({1,1,3,3,3}, 1), 5);
}

TEST(max_distinct_elementsTest, NegativeNumbers) {
    // Overlapping negatives with k=2 should allow 4 distinct.
    EXPECT_EQ(call_max_distinct_elements({-5,-5,-4,-3}, 2), 4);
}

TEST(max_distinct_elementsTest, WideKAcrossGaps) {
    // Far apart centers but huge k allows distinct picks across.
    EXPECT_EQ(call_max_distinct_elements({-10, 10}, 100), 2);
}

TEST(max_distinct_elementsTest, NonOverlappingIntervals) {
    // With k=0, intervals are singletons; answer equals number of unique values.
    EXPECT_EQ(call_max_distinct_elements({-5, -5, 0, 7, 7, 8}, 0), 4);
}

TEST(max_distinct_elementsTest, RangeCapacitySmallerThanCount) {
    // Centers {0,0,0,0}; k=1 => each interval [-1,1], capacity 3
    EXPECT_EQ(call_max_distinct_elements({0,0,0,0}, 1), 3);
}


TEST(max_distinct_elementsTest, MixedSignsTightK) {
    // Intervals: [-1,1], [-2,0], [9,11] => should fit 3 distinct.
    EXPECT_EQ(call_max_distinct_elements({0, -1, 10}, 1), 3);
}

TEST(max_distinct_elementsTest, LargeMultisetWithCapacityBottleneck) {
    // Ten zeros, k=3 => interval [-3,3], capacity = 7 integers {-3..3}
    // So max distinct is min(10, 7) = 7.
    EXPECT_EQ(call_max_distinct_elements({0,0,0,0,0,0,0,0,0,0}, 3), 7);
}

TEST(max_distinct_elementsTest, SparseCentersButSmallK) {
    // Centers far apart, but small k still allows all distinct (n=5).
    EXPECT_EQ(call_max_distinct_elements({-100, -50, 0, 50, 100}, 1), 5);
}

