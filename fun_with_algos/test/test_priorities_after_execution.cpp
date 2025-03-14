//
// Created by andreas on 14.03.25.
//
#include "./../priorities_after_execution.h"
#include "gtest/gtest.h"

TEST(TestPrioritiesAfterExecution, simple1)
{
    std::vector<int> process_priorities{6, 6, 6, 1, 2, 2};
    std::vector<int> expected_result{3, 6, 0};
    EXPECT_EQ(expected_result, priorities_after_execution(process_priorities));
}
