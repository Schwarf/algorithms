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

TEST(TestRobotCollissions, complex1) {
    std::vector<int> positions{7, 20, 78, 41, 59, 39, 88, 44, 66, 46, 84, 16, 92, 14, 82, 19, 69, 5, 56, 13, 11, 85, 3,
                               28, 71, 9, 34, 47, 30, 54, 91, 68, 93, 23, 79, 77, 53, 4, 45, 75, 37, 26, 42, 76, 50, 73,
                               99, 97, 55, 48, 10};
    std::vector<int> healths{232, 384, 466, 561, 603, 568, 515, 349, 99, 247, 726, 311, 781, 545, 567, 270, 10, 506,
                             908, 798, 432, 647, 866, 576, 76, 810, 666, 85, 355, 155, 891, 381, 412, 65, 809, 60, 304,
                             745, 456, 228, 559, 959, 231, 322, 366, 878, 549, 216, 932, 978, 367};
    std::string directions("RRLLLRLRRLLRLRLRLLLLLLLRRRLRLRLRLLLLRLLLLRLLLRLLRRL");
    std::vector<int> expected_result{232, 383, 564, 311, 545, 270, 506, 866, 807, 85, 155, 304, 745, 957, 925, 977};
    EXPECT_EQ(survivedRobotsHealths(positions, healths, directions), expected_result);
}

TEST(TestRobotCollissions, complex2) {
    std::vector<int> positions{7, 50, 31, 41, 27, 87, 98, 63, 18, 94, 85, 60, 73, 79, 53, 100, 32, 26, 30, 43, 22, 69,
                               89, 40, 45, 25, 24, 65, 97, 83, 81, 37, 52, 58, 61, 55, 66, 3, 80, 51, 21, 57, 44, 49,
                               77, 86, 47, 6, 67, 39, 64, 19, 17, 75, 33, 71, 11, 20, 10, 74, 46, 70, 54, 16, 28, 56,
                               76, 78, 5, 35, 68};
    std::vector<int> healths{587, 807, 457, 92, 509, 657, 233, 299, 681, 361, 193, 614, 628, 877, 130, 344, 975, 763,
                             172, 835, 768, 444, 236, 620, 659, 445, 847, 547, 218, 800, 964, 211, 89, 502, 194, 25,
                             136, 557, 480, 558, 461, 625, 814, 199, 32, 413, 833, 985, 821, 496, 302, 694, 135, 630,
                             759, 839, 927, 332, 999, 174, 920, 783, 411, 526, 258, 464, 40, 745, 406, 760, 104};
    std::string directions("LRLLLLLRLRRRRRLRRRLLLRRLRLLRLRRRLRLLRLRRLRLRRRRRRRRRRRRLRLRRLLLRLRRLLLL");
    std::vector<int> expected_result{359, 877, 344, 969, 759, 236, 799, 964, 557, 480, 831, 984, 923, 999, 406};
    EXPECT_EQ(survivedRobotsHealths(positions, healths, directions), expected_result);
}
