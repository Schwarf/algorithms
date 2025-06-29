//
// Created by andreas on 29.06.25.
//

#include "gtest/gtest.h"
#include "./../max_profit_in_job_scheduling.h"

TEST(JobSchedulingTest, ReturnsZeroForEmptyInput) {
    std::vector<int> start_times;
    std::vector<int> end_times;
    std::vector<int> profits;
    EXPECT_EQ(job_scheduling(start_times, end_times, profits), 0);
}

TEST(JobSchedulingTest, SingleJob) {
    std::vector<int> start_times = {1};
    std::vector<int> end_times   = {3};
    std::vector<int> profits     = {50};
    EXPECT_EQ(job_scheduling(start_times, end_times, profits), 50);
}

TEST(JobSchedulingTest, NonOverlappingJobs) {
    std::vector<int> start_times = {1, 3, 6};
    std::vector<int> end_times   = {3, 5, 19};
    std::vector<int> profits     = {50, 20, 100};
    // 50 + 20 + 100 = 170
    EXPECT_EQ(job_scheduling(start_times, end_times, profits), 170);
}

TEST(JobSchedulingTest, OverlappingJobs) {
    std::vector<int> start_times = {1, 2, 4};
    std::vector<int> end_times   = {3, 5, 6};
    std::vector<int> profits     = {50, 20, 70};
    // Optimal: job0 (50) + job2 (70) = 120
    EXPECT_EQ(job_scheduling(start_times, end_times, profits), 120);
}

TEST(JobSchedulingTest, MixedJobs) {
    std::vector<int> start_times = {1, 2, 3, 6};
    std::vector<int> end_times   = {3, 100, 5, 19};
    std::vector<int> profits     = {50, 200, 20, 100};
    // Best: skip {1,3,50}, choose {2,100,200} = 200
    EXPECT_EQ(job_scheduling(start_times, end_times, profits), 200);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////


TEST(JobSchedulingTestBottomUp, ReturnsZeroForEmptyInput) {
    std::vector<int> start_times;
    std::vector<int> end_times;
    std::vector<int> profits;
    EXPECT_EQ(job_scheduling_bottom_up(start_times, end_times, profits), 0);
}

TEST(JobSchedulingTestBottomUp, SingleJob) {
    std::vector<int> start_times = {1};
    std::vector<int> end_times   = {3};
    std::vector<int> profits     = {50};
    EXPECT_EQ(job_scheduling_bottom_up(start_times, end_times, profits), 50);
}

TEST(JobSchedulingTestBottomUp, NonOverlappingJobs) {
    std::vector<int> start_times = {1, 3, 6};
    std::vector<int> end_times   = {3, 5, 19};
    std::vector<int> profits     = {50, 20, 100};
    // 50 + 20 + 100 = 170
    EXPECT_EQ(job_scheduling_bottom_up(start_times, end_times, profits), 170);
}

TEST(JobSchedulingTestBottomUp, OverlappingJobs) {
    std::vector<int> start_times = {1, 2, 4};
    std::vector<int> end_times   = {3, 5, 6};
    std::vector<int> profits     = {50, 20, 70};
    // Optimal: job0 (50) + job2 (70) = 120
    EXPECT_EQ(job_scheduling_bottom_up(start_times, end_times, profits), 120);
}

TEST(JobSchedulingTestBottomUp, MixedJobs) {
    std::vector<int> start_times = {1, 2, 3, 6};
    std::vector<int> end_times   = {3, 100, 5, 19};
    std::vector<int> profits     = {50, 200, 20, 100};
    // Best: skip {1,3,50}, choose {2,100,200} = 200
    EXPECT_EQ(job_scheduling_bottom_up(start_times, end_times, profits), 200);
}
