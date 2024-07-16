//
// Created by andreas on 16.07.24.
//
#include "stacks_and_queues/robot_collisions.h"
#include "gtest/gtest.h"

TEST(TestRobotCollissions, simple1) {
    std::vector<int> positions{5, 4, 3, 2, 1};
    std::vector<int> healths{2, 17, 9, 15, 10};
    std::string directions("RRRRR");
    std::vector<int> expected_result{2, 17, 9, 15, 10};
    EXPECT_EQ(survivedRobotsHealths(positions, healths, directions), expected_result);
}

TEST(TestRobotCollissions, simple2) {
    std::vector<int> positions{3, 5, 2, 6};
    std::vector<int> healths{10, 10, 15, 12};
    std::string directions("RLRL");
    std::vector<int> expected_result{14};
    EXPECT_EQ(survivedRobotsHealths(positions, healths, directions), expected_result);
}

TEST(TestRobotCollissions, simple3) {
    std::vector<int> positions{3, 5, 2, 6};
    std::vector<int> healths{10, 10, 11, 11};
    std::string directions("RLRL");
    std::vector<int> expected_result{};
    EXPECT_EQ(survivedRobotsHealths(positions, healths, directions), expected_result);
}