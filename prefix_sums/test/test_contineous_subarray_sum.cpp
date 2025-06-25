//
// Created by andreas on 25.06.25.
//

#include "gtest/gtest.h"
#include "./../contineous_subarray_sum.h"

TEST(HasGoodSubarrayTest, ExampleHasSubarray) {
    std::vector<int> nums = {23, 2, 4, 7};
    EXPECT_TRUE(has_valid_subarray_sum(nums, 6));
}

TEST(HasGoodSubarrayTest, ExampleNoSubarray) {
    std::vector<int> nums = {5, 0, 0, 0};
    EXPECT_FALSE(has_valid_subarray_sum(nums, 3));
}

TEST(HasGoodSubarrayTest, EmptyArray) {
    std::vector<int> nums;
    EXPECT_FALSE(has_valid_subarray_sum(nums, 5));
}

TEST(HasGoodSubarrayTest, SingleElement) {
    std::vector<int> nums = {10};
    EXPECT_FALSE(has_valid_subarray_sum(nums, 5));
}

TEST(HasGoodSubarrayTest, TwoElementsMultiple) {
    std::vector<int> nums = {3, 3};
    EXPECT_TRUE(has_valid_subarray_sum(nums, 3));
}

TEST(HasGoodSubarrayTest, LargeElements) {
    std::vector<int> nums = {2000000000, 2000000000};
    EXPECT_TRUE(has_valid_subarray_sum(nums, 2000000000));
}