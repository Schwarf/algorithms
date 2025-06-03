//
// Created by andreas on 03.06.25.
//
#include "graphs/maximum_reward_from_boxes.h"
#include "gtest/gtest.h"

TEST(TestMaximumRewardFromBoxes, simple1)
{
    std::vector<int> status = {1, 0, 1, 0};
    std::vector<int> rewards = {7, 5, 4, 100};
    std::vector<std::vector<int>> keys = {{}, {}, {1}, {}};
    std::vector<std::vector<int>> contained_boxes{{1, 2}, {3}, {}, {}};
    std::vector<int> initial_boxes = {0};
    constexpr int expected_result{16};
    EXPECT_EQ(max_rewards_from_boxes(status, rewards, keys, contained_boxes, initial_boxes), expected_result);
}

TEST(TestMaximumRewardFromBoxes, simple2)
{
    std::vector<int> status = {1, 0, 0, 1};
    std::vector<int> rewards = {7, 5, 4, 100};
    std::vector<std::vector<int>> keys = {{}, {}, {1}, {}};
    std::vector<std::vector<int>> contained_boxes{{1, 2}, {3}, {}, {}};
    std::vector<int> initial_boxes = {3};
    constexpr int expected_result{100};
    EXPECT_EQ(max_rewards_from_boxes(status, rewards, keys, contained_boxes, initial_boxes), expected_result);
}

TEST(TestMaximumRewardFromBoxes, simple3)
{
    std::vector<int> status = {1,0,0,0,0,0};
    std::vector<int> rewards = {1,1,1,1,1,1};
    std::vector<std::vector<int>> keys = {{1,2,3,4,5},{},{},{},{},{}};
    std::vector<std::vector<int>> contained_boxes{{1,2,3,4,5},{},{},{},{},{}};
    std::vector<int> initial_boxes = {0};
    constexpr int expected_result{6};
    EXPECT_EQ(max_rewards_from_boxes(status, rewards, keys, contained_boxes, initial_boxes), expected_result);
}

TEST(TestMaximumRewardFromBoxes, simple4)
{
    std::vector<int> status = {0,0,0,0,0,0};
    std::vector<int> rewards = {1,1,1,1,1,1};
    std::vector<std::vector<int>> keys = {{1,2,3,4,5},{},{},{},{},{}};
    std::vector<std::vector<int>> contained_boxes{{1,2,3,4,5},{},{},{},{},{}};
    std::vector<int> initial_boxes = {0};
    constexpr int expected_result{0};
    EXPECT_EQ(max_rewards_from_boxes(status, rewards, keys, contained_boxes, initial_boxes), expected_result);
}
