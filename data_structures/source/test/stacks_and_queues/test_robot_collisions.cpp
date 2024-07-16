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


TEST(TestRobotCollissions, simple4) {
    std::vector<int> positions{5, 4, 3, 2, 1};
    std::vector<int> healths{2, 17, 9, 15, 10};
    std::string directions("RRRRR");
    std::vector<int> expected_result{2, 17, 9, 15, 10};
    EXPECT_EQ(survivedRobotsHealths(positions, healths, directions), expected_result);
}

TEST(TestRobotCollissions, simple5) {
    std::vector<int> positions{4, 47};
    std::vector<int> healths{15, 24};
    std::string directions("RR");
    std::vector<int> expected_result{15, 24};
    EXPECT_EQ(survivedRobotsHealths(positions, healths, directions), expected_result);
}


TEST(TestRobotCollissions, medium1) {
    std::vector<int> positions{7, 4, 11, 5, 24, 39, 10, 21, 13, 6, 33};
    std::vector<int> healths{25, 5, 17, 40, 21, 30, 39, 5, 33, 36, 24};
    std::string directions("RLRRLRRLRLL");
    std::vector<int> expected_result{25, 5, 17, 39, 30, 39, 30};
    EXPECT_EQ(survivedRobotsHealths(positions, healths, directions), expected_result);
}

TEST(TestRobotCollissions, medium2) {
    std::vector<int> positions{2, 26, 6, 16, 4, 15, 39, 48, 7, 9, 49, 35, 3};
    std::vector<int> healths{26, 11, 3, 46, 47, 3, 42, 10, 4, 4, 16, 43, 7};
    std::string directions("LRRLLRLRRLRLL");
    std::vector<int> expected_result{26, 44, 47, 42, 10, 16, 42, 7};
    EXPECT_EQ(survivedRobotsHealths(positions, healths, directions), expected_result);
}

TEST(TestRobotCollissions, medium3) {
    std::vector<int> positions{1, 8, 20, 48, 43, 25, 46, 39, 23, 28, 17, 3, 6, 19, 2, 50};
    std::vector<int> healths{40, 34, 28, 46, 2, 5, 18, 24, 24, 30, 32, 33, 44, 10, 22, 32};
    std::string directions("RRRRRRRRRLLLRRRR");
    std::vector<int> expected_result{39, 33, 46, 2, 18, 24, 44, 10, 32};
    EXPECT_EQ(survivedRobotsHealths(positions, healths, directions), expected_result);
}
