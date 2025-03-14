//
// Created by andreas on 14.03.25.
//
#include "./../execute_processes.h"
#include "gtest/gtest.h"

TEST(TestExecuteProcesses, simple1)
{
    std::vector<int> processes = {10, 10, 5};
    constexpr int expected_result{20};
    EXPECT_EQ(time_to_execute_process(processes), expected_result);
}

TEST(TestExecuteProcesses, simple2)
{
    std::vector<int> processes = {10, 5, 5};
    constexpr int expected_result{18};
    EXPECT_EQ(time_to_execute_process(processes), expected_result);
}


TEST(TestExecuteProcesses, simple3)
{
    std::vector<int> processes = {10, 10, 5, 5};
    constexpr int expected_result{23};
    EXPECT_EQ(time_to_execute_process(processes), expected_result);
}
