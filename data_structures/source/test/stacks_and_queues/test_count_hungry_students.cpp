//
// Created by andreas on 08.04.24.
//
#include "gtest/gtest.h"
#include "stacks_and_queues/count_hungry_students.h"

TEST(TestCountHungryStudents, simple1) {
    const std::vector<int> students{1, 1, 0, 0};
    const std::vector<int> dishes{1, 0, 1, 0};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, count_hungry_students(students, dishes));
}

TEST(TestCountHungryStudents, simple2) {
    const std::vector<int> students{1, 1, 0, 0};
    const std::vector<int> dishes{0, 1, 0, 1};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, count_hungry_students(students, dishes));
}

TEST(TestCountHungryStudents, simple3) {
    const std::vector<int> students{1, 1, 1, 0, 0, 1};
    const std::vector<int> dishes{1, 0, 0, 0, 1, 1};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, count_hungry_students(students, dishes));
}

TEST(TestCountHungryStudents, simple4) {
    const std::vector<int> students{0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1};
    const std::vector<int> dishes{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, count_hungry_students(students, dishes));
}


TEST(TestCountHungryStudents, simple5) {
    const std::vector<int> students{0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0};
    const std::vector<int> dishes{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, count_hungry_students(students, dishes));
}

TEST(TestCountHungryStudents, simple6) {
    const std::vector<int> students{0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0};
    const std::vector<int> dishes{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, count_hungry_students(students, dishes));
}

TEST(TestCountHungryStudents, simple7) {
    const std::vector<int> students{0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
                                    0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0};
    const std::vector<int> dishes{1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
                                  1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0};
    constexpr int expected_result{16};
    EXPECT_EQ(expected_result, count_hungry_students(students, dishes));
}


TEST(TestCountHungryStudentsOptimized, simple1) {
    const std::vector<int> students{1, 1, 0, 0};
    const std::vector<int> dishes{1, 0, 1, 0};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, count_hungry_students_optimized(students, dishes));
}

TEST(TestCountHungryStudentsOptimized, simple2) {
    const std::vector<int> students{1, 1, 0, 0};
    const std::vector<int> dishes{0, 1, 0, 1};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, count_hungry_students_optimized(students, dishes));
}

TEST(TestCountHungryStudentsOptimized, simple3) {
    const std::vector<int> students{1, 1, 1, 0, 0, 1};
    const std::vector<int> dishes{1, 0, 0, 0, 1, 1};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, count_hungry_students_optimized(students, dishes));
}

TEST(TestCountHungryStudentsOptimized, simple4) {
    const std::vector<int> students{0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1};
    const std::vector<int> dishes{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, count_hungry_students_optimized(students, dishes));
}


TEST(TestCountHungryStudentsOptimized, simple5) {
    const std::vector<int> students{0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0};
    const std::vector<int> dishes{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, count_hungry_students_optimized(students, dishes));
}

TEST(TestCountHungryStudentsOptimized, simple6) {
    const std::vector<int> students{0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0};
    const std::vector<int> dishes{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, count_hungry_students_optimized(students, dishes));
}

TEST(TestCountHungryStudentsOptimized, simple7) {
    const std::vector<int> students{0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
                                    0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0};
    const std::vector<int> dishes{1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
                                  1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0};
    constexpr int expected_result{16};
    EXPECT_EQ(expected_result, count_hungry_students_optimized(students, dishes));
}
