//
// Created by andreas on 29.12.23.
//
#include "gtest/gtest.h"
#include "./../minimum_difficulty_job_schedule.h"

TEST(TestMinimumSchedule, simple1) {
    const std::vector<int> job_difficulty{6, 5, 4, 3, 2, 1};
    constexpr int days{2};
    constexpr int expected_result{7};
    EXPECT_EQ(min_difficulty_job_schedule_top_down(job_difficulty, days), expected_result);
}

TEST(TestMinimumSchedule, simple2) {
    const std::vector<int> job_difficulty{1, 1, 1};
    constexpr int days{4};
    constexpr int expected_result{-1};
    EXPECT_EQ(min_difficulty_job_schedule_top_down(job_difficulty, days), expected_result);
}

TEST(TestMinimumSchedule, simple3) {
    const std::vector<int> job_difficulty{1, 1, 1};
    constexpr int days{3};
    constexpr int expected_result{3};
    EXPECT_EQ(min_difficulty_job_schedule_top_down(job_difficulty, days), expected_result);
}


TEST(TestMinimumSchedule, medium1) {
    const std::vector<int> job_difficulty{1, 2, 4, 6, 7, 89, 45, 176, 18, 1, 5, 6, 13, 90, 1, 4, 8, 9, 12};
    constexpr int days{10};
    constexpr int expected_result{221};
    EXPECT_EQ(min_difficulty_job_schedule_top_down(job_difficulty, days), expected_result);
}

